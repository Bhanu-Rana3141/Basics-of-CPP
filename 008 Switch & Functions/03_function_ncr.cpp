#include<iostream>
using namespace std;

int factorial(int n){
    int fact = 1;
    for(int i=1; i<=n; i++){
        fact *= i;
    }
    return fact;
}

int ncr(int n,int r){
    int numerator = factorial(n);
    int denomenator = factorial(r) * factorial(n-r);
    return numerator/denomenator; 
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int r;
    cout<<"Enter r: ";
    cin>>r;

    int ans = ncr(n,r);
    cout<<"NCR: "<<ans;
}