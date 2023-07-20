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

    bool isSorted = true;
    for(int i=1; i<v.size(); i++){
        if(v[i-1] >= v[i]){
            isSorted=false;
            break;
        }
    }

    if(isSorted==true){
        cout<<"Sorted";
    }else{
        cout<<"Not sorted";
    }
    return 0;
}