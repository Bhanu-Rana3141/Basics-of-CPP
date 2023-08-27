#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=1; j<=n-i+1; j++){
            cout<<" ";
        }
        int first=1;
        for(int j=0; j<=i; j++){
            cout<<first<<" ";
            first=first*(i-j)/(j+1);
        }
        cout<<endl;
    }
    return 0;
}