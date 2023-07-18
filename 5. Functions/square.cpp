#include<iostream>
using namespace std;

int square(int i){
    int square = i*i;
    return square;
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    for(int i=1; i<=n; i++){
        cout<<square(i)<<" ";
    }

    return 0;
}