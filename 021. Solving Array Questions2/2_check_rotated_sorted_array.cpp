#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isRotated_Sorted(vector<int>& arr, int n){
    int count = 0;
    for(int i=1; i<n; i++){
        if(arr[i-1] > arr[i]){
            count++;
        }
    }

    if(arr[n-1] > arr[0]){
        count++;
    }

    return count<=1;
}

int main() {
    
    int n;
    cout<<"Enter n: ";
    cin>>n;

    vector<int>arr(n); 

    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    int ans = isRotated_Sorted(arr,n);

    if(ans == 1){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}