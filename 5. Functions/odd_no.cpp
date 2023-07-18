#include<iostream>
using namespace std;

void odd(int n){
    for(int i=1; i<=n; i++){
        if(i%2!=0){
            cout<<i<<" ";
        }
    }
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    odd(n);
    return 0;
}