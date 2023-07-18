#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int factorial =1;
    if(n==0){
        factorial=1;
    }
    else{
        for(int i=1; i<=n; i++){
            factorial*=i;
        }
    }
    cout<<factorial;
    return 0;
}