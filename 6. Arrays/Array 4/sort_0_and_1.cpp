#include<iostream>
using namespace std;

// Approach - 1 (Sorting)

// void sortZeroOne(int arr[],int n){
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[i]>arr[j]){
//             int temp=arr[i];
//             arr[i]=arr[j];
//             arr[j] = temp;
//             }
//         }
//     }
// }


// Approach -2 (count no of 0 and 1 and place them according to their count)

// void sortZeroOne(int arr[],int n){
//     int zeroCount=0;
   
//     for(int i=0; i<n; i++){
//         if(arr[i]==0){
//             zeroCount++;
//         }
//     }
//     for(int i=0; i<n; i++){
//         if(i<zeroCount){
//             arr[i]=0;
//         }
//         else{
//             arr[i]=1;
//         }
//     }
    
// }




// APPROACH -3   OPTIMISED SOLUTION USING 2 COUNTER VARIABLES

void sortZeroOne(int arr[],int n){
    int i=0,j=n-1;
    while(i<j){
        if(arr[i]==1 && arr[j]==0){
           swap(arr[i],arr[j]);
           i++,j--;
        }
        if(arr[i] == 0){
            i++;
        }
        if(arr[j]==1){
            j--;
        }
    }
    return;
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n];
    cout<<"Enter array ele: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sortZeroOne(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}