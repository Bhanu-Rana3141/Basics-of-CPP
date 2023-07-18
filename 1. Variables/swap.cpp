#include<iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;

    // int temp = a;
    // a=b;
    // b=temp;

    a=a+b;
    b=a-b;
    a=a-b;

    cout<<"a: "<<a<<endl<<"b: "<<b;

    return 0;
}