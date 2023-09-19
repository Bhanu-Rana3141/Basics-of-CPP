#include<iostream>
using namespace std;

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

    if(n==0 || n==1){
        cout<<"neither prime nor composite";
        return 0;
    }
    
    int ans = isPrime(n);

    if(ans==1){
        cout<<"Prime";
    }
    else{
        cout<<"Not Prime";
    }
    return 0;
}