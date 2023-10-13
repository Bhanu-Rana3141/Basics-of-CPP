#include<iostream>
#include<algorithm>
using namespace std;


void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return;
}

bool isPrime(int n){
    for(int i=2; i<n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

/*  check whether no is prime or not ?   TC: O(n)
    if(n==0 || n==1) {
        cout<<"Neither prime nor composite";
        return 0;
    }
    if(isPrime(n) == 1) {
        cout<<"not prime";
    }
    else{
        cout<<"prime";
    }
*/
    
    
 /* COUNT PRIME -> TC - O(n^2)

    int count = 0;
    for(int i=2; i<n; i++) {
        if(isPrime(i)){
            count++;
        } 
    }
    cout<<"count: "<<count;
*/

// OPTIMISATION - Sieve of Eratosthenes :  TC - O(n log logn)
   
    int arr[n];
    fill(arr,arr+n,1);    // inbuilt function to assign value to all array elements

    printArray(arr,n);

    arr[0]=arr[1] = 0;
    
    int count = 0;
    for(int i=2; i<n; i++) {
        if(arr[i] == 1){
            count++;
        }
        for(int j=2*i; j<n; j+=i){
            arr[j] = 0;
        }
    }
    printArray(arr,n);

    cout<<count;
    
    return 0;
}