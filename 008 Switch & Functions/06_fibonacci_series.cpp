#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int a=0;
    int b=1;
    int sum = 0;

    int fiboNum_sum=0;
    for(int i=1; i<n; i++){
        a=b;
        b=sum;
        sum=a+b;   
        fiboNum_sum += sum;     
    }cout<<endl;

    cout<<"Sum: "<<sum<<endl;
    cout<<"fibo num Sum: "<<fiboNum_sum;
    return 0;
}