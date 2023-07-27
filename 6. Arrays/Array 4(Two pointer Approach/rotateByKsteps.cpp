#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void rotate(int arr[],int start,int end){
    // while(i<j){
    //     swap(arr[i],arr[j]);
    //     i++,j--;
    // }
    for(int i=start,j=end; i<j; i++,j--){
        swap(arr[i],arr[j]);
    }
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int k;
    cout<<"Enter k: ";
    cin>>k;
    k=k%n;

    cout<<"Before rotation: ";
    printArray(arr,n);
    cout<<endl;
    
    rotate(arr,0,n-1); // reverse all elements
    printArray(arr,n);
    cout<<endl;

    rotate(arr,0,k-1); //k elements reverse
    printArray(arr,n);
    cout<<endl;

    rotate(arr,k,n-1);// k to n elements reverse
    printArray(arr,n);

    return 0;
}