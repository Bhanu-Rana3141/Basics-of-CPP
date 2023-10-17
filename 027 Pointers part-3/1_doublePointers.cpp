#include<iostream>
using namespace std;

int main() {
    int i = 5;
    int* p = &i;
    int** p2 = &p;

    cout<<endl;
    // Accessing value in i
    cout<<i<<endl;
    cout<<*p<<endl;
    cout<<**p2<<endl;

    cout<<endl;
    cout<<"Printing p containing address of i: "<<p<<endl;
    cout<<"Address of p: "<<&p<<endl;
    cout<<"Printing p2 containg address of p : "<<p2<<endl;
    cout<<"printing address of i using p2 : "<<*p2<<endl;
    cout<<endl;

    // printing value in p
    cout<<&i<<endl;
    cout<<p<<endl;
    cout<<*p2<<endl;
    cout<<endl;

    // printing value in p2
    cout<<&p<<endl;
    cout<<p2<<endl;
    cout<<endl<<endl;

    return 0;   
}