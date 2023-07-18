#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"Enter n: ";
    cin>>n;

    int count=0;
    int sum=0;
    while(n>0){
        int x = n%10;
        count++;
        sum+=x;
        n/=10;
    }
    cout<<count<<endl<<sum;
    return 0;
}