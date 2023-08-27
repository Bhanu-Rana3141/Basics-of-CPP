#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"Enter n: ";
    cin>>n;

    int rev=0;
    while(n>0) {
        int x=n%10;
        rev=rev*10+x;
        n/=10;
    }
    cout<<rev;
    return 0;
}