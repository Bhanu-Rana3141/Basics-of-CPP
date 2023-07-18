#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"Enter n: ";
    cin>>n;

    for(int i=1; i<=n-1; i++){  
        for(int j=1; j<=n-i; j++){
            cout<<" ";
        }
        int m = i*2-1;
        for(int j=1; j<=m; j++){
            if(j==1 || j==m){
                cout<<i;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    for(int i=1; i<=n*2-1; i++){
        cout<<n;
    }
    return 0;
}