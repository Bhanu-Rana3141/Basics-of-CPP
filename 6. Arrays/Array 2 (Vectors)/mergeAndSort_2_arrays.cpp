#include<iostream>
#include<vector>

using namespace std;

int main() {
    int m;
    cout<<"Enter m: ";
    cin>>m;

    int n;
    cout<<"Enter n: ";
    cin>>n;


    cout<<"Enter array 1 ele: ";
    vector<int>arr1(m);
    for(int i=0; i<arr1.size(); i++){
        cin>>arr1[i];
    }

    cout<<"Enter array 2 ele: ";
    vector<int>arr2(n);
    for(int i=0; i<arr2.size(); i++){
        cin>>arr2[i];
    }

   
    // vector<int>resArr(m+n);
    // for(int i=0; i<m; i++){
    //     resArr[i] = arr1[i];
    // }

    // for(int i=0; i<n; i++){
    //     resArr[i] = arr2[i];
    // }


    // for(int i=0; i<resArr.size(); i++){
    //     cout<<resArr[i]<<" ";
    // }



    return 0;
}