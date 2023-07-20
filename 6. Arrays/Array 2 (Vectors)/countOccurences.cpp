#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    vector<int>v(n);
    for(int i=0; i<v.size(); i++){
        cin>>v[i];
    }

    int x;
    cout<<"Enter element: ";
    cin>>x;

    int count=0;
    for(int i=0; i<v.size(); i++){
        if(v[i] == x){
            count++;
        }
    }

    cout<<"count: "<<count;


    return 0;
}