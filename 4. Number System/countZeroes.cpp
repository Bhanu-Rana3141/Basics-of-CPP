#include<iostream>
using namespace std;

int main() {
    int decimal;
    cout<<"Enter decimal no: ";
    cin>>decimal;

    int binary=0,power=1;
    while(decimal>0){
        int x = decimal%2;
        binary += power*x;
        power*=10;
        decimal/=2;
    }

    cout<<"binary no: "<<binary<<endl;

    int zeroesCount=0;
    while(binary>0){
        int x=binary%10;
        if(x==0){
            zeroesCount++;
        }
        binary/=10;
    }

    cout<<"no of zeroes: "<<zeroesCount;

    return 0;
}