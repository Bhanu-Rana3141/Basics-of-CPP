#include<iostream>
using namespace std;

// SIMPLE APPROACH

int middleElement(int array[],int n){
    int start=0;
    int end=n-1;
    int mid = start+(end-start)/2;
    return array[mid];
}

int main() {
    int n; 
    cout<<"Enter n: ";
    cin>>n;

    int array[n];
    cout<<"Size of Array: "<<n<<endl;
    cout<<"Enter array elements: ";

    for(int i=0; i<n; i++){
        cin>>array[i];
    }

    // int ans=-1;
    // for(int i=0; i<n; i++){
    //     for(int j=i+1; j<n; j++){
    //         for(int k=j+1; k<n; k++){
    //              if(array[j] > array[i] && array[j] < array[k]){
    //                 ans = array[i];
    //              }
    //         }
    //     }
    // }

    

    cout<<"Mid element: "<<middleElement(array,n);

    return 0;
}