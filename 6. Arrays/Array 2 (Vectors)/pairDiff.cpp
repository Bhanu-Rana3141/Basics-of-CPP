#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    cout<<"Enter array ele: ";
    vector<int>arr(n);
    for(int i=0; i<arr.size(); i++){
        cin>>arr[i];
    }



    int target_diff;
    cout<<"Enter target diff: ";
    cin>>target_diff;

    int pairs=0;
    bool ans = false;

    //APPROACH - 1
    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[j]-arr[i] == target_diff){
                pairs++;
                ans = true;
            }
        }
    }

    //APPROACH - 2 

    // for(int i=arr.size()-1; i>=0; i--){
    //     for(int j=i-1; j>=0; j--){
    //         if(arr[i]-arr[j] == target_diff){
    //             pairs++;
    //             ans=true;
    //         }
    //     }
    // }

    cout<<"Pairs present : "<<ans<< " and total pairs: "<<pairs;

    return 0;
}