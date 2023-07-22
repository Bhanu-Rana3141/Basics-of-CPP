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

    int x;
    cout<<"Enter x: ";
    cin>>x;

    bool ans = false;
    int pairs=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j] == x){
                pairs++;
                ans=true;
            }
        }
    }

    if(ans==true){
        cout<<"Pairs present: Yes";
    }else{
        cout<<"pairs present: NO";
    }
   
   
    cout<<"\nTotal pairs: "<<pairs;
    return 0;
}