#include<iostream>
using namespace std;

void prime(int start , int end){
    for(int i=start; i<=end; i++){
        if(i==0 || i==1){
            continue;
        }
        bool isPrime = true;
        for(int j=2; j<=i/2; j++){
            if(i%j==0){
                isPrime=false;
                break;
            }
        }
        if(isPrime==true){
            cout<<i<<" ";
        }
    }
}

int main() {
    int start;
    cout<<"Enter start: ";
    cin>>start;

    int end; 
    cout<<"Enter end: ";
    cin>>end;

    prime(start,end);

    return 0;
}