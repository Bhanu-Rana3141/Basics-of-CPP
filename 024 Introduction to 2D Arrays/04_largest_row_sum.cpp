#include<iostream>
#include<limits.h>
using namespace std;

int main() {

    cout<<"Enter n: ";
    int n;
    cin>>n;

    cout<<"Enter m: ";
    int m;
    cin>>m;

    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    int max_sum = INT_MIN;
    int rowIndex = 0 ;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<m; j++) {
            sum += arr[i][j];
        }
        if(sum > max_sum){
            max_sum = sum;
            rowIndex = i;
        }
    }

    cout<<"Row having largest sum: "<<rowIndex<<" : "<<max_sum;
    return 0;
}