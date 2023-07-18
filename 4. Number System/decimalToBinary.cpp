#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"Enter decimal no: ";
    cin>>n;

    int decimal = n;
    int binary=0,power=1;
    while(n>0){
        int x = n%2; //parity
        binary += x*power;
        power*=10;
        n/=2;
    }

    cout<<"Binary of "<<decimal<<" : "<<binary;
    return 0;
}