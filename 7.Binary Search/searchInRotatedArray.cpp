#include<iostream>
#include<limits.h>
using namespace std;

// SOLVING BY USING PIVOT CONCEPT

// int pivot(int arr[],int n){
//     int s=0;
//     int e=n-1;
//     int mid = s+(e-s)/2;

//     while(s<e){
//         if(arr[mid]>arr[0]){
//             s=mid+1;
//         }
//         else{
//             e=mid;
//         }
//         mid=s+(e-s)/2;
//     }
//     return s;
// }

// int binarySearch(int arr[],int s,int e,int key){
//    int mid = s+(e-s)/2;
//    while(s<=e){
//     if(arr[mid] == key){
//         return mid;
//     }
//     else if(arr[mid] > key){
//         e=mid-1;
//     }
//     else{
//         s=mid+1;
//     }
//     mid=s+(e-s)/2;
//    }
//     return -1;
// }


//SOLVING BY USING PEAK ELEMENT
int peakElement(int arr[],int n){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;

    while(s<e){
        if(arr[mid] < arr[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}

int binarySearch(int arr[],int s,int e,int k){
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid] == k){
            return mid;
        }
        else if(arr[mid]>k){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
}

int ans(int arr[],int peak,int n,int k){
    if(k>=arr[0] && k<=peak){
        return binarySearch(arr,0,peak,k);
    }
    else{
        return binarySearch(arr,peak+1,n-1,k);
    }
}

int main() {    
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

     int key;
     cout<<"Enter key: ";
     cin>>key;

    // int pivotEle = pivot(arr,n);
    // if(key >= arr[pivotEle] && key<=arr[n-1]){
    //     cout<< binarySearch(arr,pivotEle,n-1,key);
    // }else{
    //     cout<<binarySearch(arr,0,pivotEle-1,key);
    // }

    // Peak element
    int peak = peakElement(arr,n);

    // int ans=-1;
    // if(key>=arr[0] && key<=peak){
    //    ans=binarySearch(arr,0,peak,key); 
    // }
    // else{
    //     ans=binarySearch(arr,peak+1,n-1,key);
    // }

    cout<<ans(arr,peak,n,key);

    return 0;
}