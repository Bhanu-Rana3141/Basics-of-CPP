#include<iostream>
using namespace std;

int countTriplets(int arr[] , int n, int x){
    int triplets=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i] + arr[j] + arr[k] == x){
                    triplets++;
                }
            }
        }
    }
    return triplets;
}

int main() {
    int n;
    cout<<"Enter size: ";
    cin>>n;

    int arr[n];

    cout<<"Enter array ele: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];    
    }

    int x;
    cout<<"Enter target sum: ";
    cin>>x;


    int tripletsCount = countTriplets(arr,n,x);
    cout<<"triplets: "<< tripletsCount; 
    
    return 0;
}