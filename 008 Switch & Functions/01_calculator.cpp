#include<iostream>
using namespace std;

int main() {
    int a;
    cout<<"Enter a: ";
    cin>>a;

    int b;
    cout<<"Enter b: ";
    cin>>b;

    char op;
    cout<<"Enter operation: ";
    cin>>op;

    switch(op){
        case '+' : cout<<"a+b: "<<a+b;
        break;
        case '-' : cout<<"a-b: "<<a-b;
        break;
        case '*' : cout<<"a*b: "<<a*b;
        break;
        case '/' : cout<<"a/b: "<<a/b;
        break;
        default: cout<<"No operation";
    }


    return 0;
}