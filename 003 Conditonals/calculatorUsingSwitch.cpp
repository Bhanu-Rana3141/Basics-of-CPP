#include<iostream>
using namespace std;

int main() {

    int a;
    cout<<"Enter a: ";
    cin>>a;
    
    int b;
    cout<<"Enter b: ";
    cin>>b;

    char inputOperator;
    cout<<"Enter inputOperator: ";
    cin>>inputOperator;

    switch(inputOperator){
        case '+' : cout<<"a+b: "<<a+b;
        break;
        case '-' : cout<<"a-b: "<<a-b;
        break;
        case '*' : cout<<"a*b: "<<a*b;
        break;
        case '/' : b>a ? cout<<"Undefined" : cout<<"a/b: "<<a/b;
        break;
        default: cout<<"Invalid operation";
    }
    return 0;
}