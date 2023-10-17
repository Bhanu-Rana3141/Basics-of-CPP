#include<iostream>
using namespace std;

/*
void print(int *p){
    cout<<p<<endl;
    cout<<*p;
}

void update(int *p){
    // pass by value in case of changing address
    // p = p+1;  // p will be treated as local variable 
    // cout<<p<<endl;

    *p = *p + 1;
}
*/

int getSum(int *arr, int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += i[arr];    // arr[i] = *(arr+i)
    }
    return sum;
}
int main() {
/*
    int value = 5;
    int *p = &value;

    // print(p); 
    
    cout<<"Before : "<<*p<<endl;
    update(p);
    cout<<"After: "<<*p<<endl;
*/



//Array in function is passed as pointer -> address of 1st element is passed

    int arr[5] = {1,2,3,4,5};
    cout<<getSum(arr,5);

    cout<<endl;

    cout<<getSum(arr+2,3);

    return 0;
}