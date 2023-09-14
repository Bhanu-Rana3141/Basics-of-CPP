#include<iostream>
using namespace std;

void printArray(int res[],int n,int m){
    for(int k=0; k<n+m; k++){
        cout<<res[k]<<" ";
    }
}

// MERGING ARR1 AND THEN ARR2 ,IN THIS APPROACH ARRAYS ARE NOT MERGED IN SORTED MANNER

// void mergeArray(int arr1[] , int n , int arr2[], int m , int res[]){
//     int i=0,j=0,k=0;

//     for(int i=0; i<n; i++){
//         res[k++] = arr1[i];
//     }

//     for(int j=0; j<m; j++){
//         res[k++] = arr2[j];
//     }
// }



// IN THIS APPROACH ARRAYS ARE MERGED IN SORTED ORDER
void mergeArray(int arr1[],int n,int arr2[],int m,int res[]){
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(arr1[i] < arr2[j]){
            res[k++] = arr1[i++]; 
        }
        else{
            res[k++] = arr2[j++];
        }
    }

    while(i<n){
        res[k++] = arr1[i++];
    }

    while(j<m){
        res[k++] = arr2[j++];
    }
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    cout<<"Enter arr1 elements: ";
    int arr1[n];
    for(int i=0; i<n; i++){
        cin>>arr1[i];
    }

    int m;
    cout<<"Enter m: ";
    cin>>m;

    cout<<"Enter arr2 elements: ";
    int arr2[m];
    for(int i=0; i<m; i++){
        cin>>arr2[i];
    }

    int res[n+m];

    mergeArray(arr1,n,arr2,m,res);
    
    printArray(res,n,m);

    return 0;
}