#include<iostream>
using namespace std;

int main() {
   
/*  DECLARATION
    int num = 5;
    int *ptr = &num;
    
    cout<<"num: "<<num<<endl;
    cout<<"Address of num: "<<&num<<endl;
    cout<<"num using pointer: "<<*ptr<<endl;
    cout<<"Address using pointer: "<<ptr<<endl;
    cout<<"size of int: "<<sizeof(num)<<endl;
    cout<<"size of pointer: "<<sizeof(ptr)<<endl;

    cout<<endl;

    double d = 4.2;
    double *ptr2 = &d;

    cout<<"Address of d: "<<ptr2<<endl;
    cout<<"Value in d: "<<*ptr2<<endl;
    cout<<"size of double: "<<sizeof(d)<<endl;
    cout<<"size of pointer: "<<sizeof(ptr2)<<endl;
*/
    
/* 
    // pointer p
    int i = 5;
    int *p = 0;
    p = &i;

    cout<<p<<endl;
    cout<<*p<<endl;

    //pointer q
    int *q = 0;
    q = &i;

    cout<<q<<endl;
    cout<<*q;
*/

/*
    int num = 5;
    int a = num;
    a++;

    cout<<"num: "<<num<<endl;   // no change in value of num 

    int *p = &num; 
    int a = *p;
    a++;
    cout<<"num: "<<num;
    
    int num = 5;
    int *ptr = &num;
    (*ptr)++;

    cout<<num;
*/  

/* COPYING A POINTER

    int num = 5;
    int *p = &num;
    int *q = p;
    cout<<"p: "<<p<<" , "<<"q: "<<q<<endl;
    cout<<"*p: "<<*p<<" , "<<"*q: "<<*q<<endl;
  */


    // Arthematic operations

    //incrementing value  
    int i = 3;
    int *t = &i;
    *t = *t + 1; 

    // Incrementing address -> value will get changed according to size of data type i.e if int then +1 means incrementing by 4
        
    cout<<"Before : "<<t<<endl;    // address - 100
    t = t+1;
    cout<<"After: "<<t;           // address - 104
    return 0;
}