#include<iostream>
using namespace std;

int main() {

    int arr[10] = {2,5,6,10};
    cout<<"Address of 0th index: "<<arr<<endl;
    cout<<"Address of 0th index: "<<&arr[0]<<endl;
    cout<<&arr<<endl;
    cout<<"Element at 0th index: "<<*arr<<endl;
    cout<<"Adding 1 to element at 0th index: "<<*arr+1<<endl;
    cout<<"moving 1 block further from starting address: "<<*(arr+1)<<endl;
    cout<<"Moving 2 blocks further from starting address : "<<*(arr+2)<<endl;
    cout<<"Element at index 3: "<<3[arr];

    // Differences in pointer and array

/*1. size 
    int temp[10];
    //temp, &temp, &temp[0] are same -> all contains address of 1st value of array
    cout<<sizeof(temp)<<endl;
    cout<<sizeof(*temp)<<endl;

    int *ptr = &temp[0];
    cout<<sizeof(ptr)<<endl;
    cout<<sizeof(*ptr)<<endl;
    cout<<sizeof(&ptr);
*/

/*2. & operator
    int a[20] = {1,2,3,4,5};
    cout<<&a<<endl;
    cout<<a<<endl;
    cout<<&a[0]<<endl;
    
    cout<<endl;

    int *p = &a[0];
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<&p<<endl; // address of p block
*/
    
/*3. Symbol table  -> cannot be changed
    int arr[10];
    //Error ->  arr = arr+1; 

    int *ptr = &arr[0];
    cout<<ptr<<endl;
    ptr = ptr + 1;
    cout<<ptr;
*/

    return 0;
}