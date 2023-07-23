#include<iostream>
#include<vector>

using namespace std;

void sortArray(int res[], int n, int m){
    for(int i=0; i<m+n; i++){
        for(int j=i+1; j<m+n; j++){
            if(res[i]>res[j]){
                int temp=res[i];
                res[i]=res[j];
                res[j]=temp;
            }
        }
    }  
}

void mergeArray(int arr1[],int arr2[] , int n,int m,int res[]){
    int k=0;
    for(int i=0; i<m; i++){
        res[k++] = arr1[i];
    }
    for(int j=0; j<n; j++){
        res[k++]=arr2[j];
    }
}

int main() {
    
    int m;
    cout<<"Enter m: ";
    cin>>m;

    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr1[m];
    cout<<"Enter arr 1 ele: ";
    for(int i=0; i<m; i++){
        cin>>arr1[i];
    }

    int arr2[n];
     cout<<"Enter arr 2 ele: ";
    for(int i=0; i<n; i++){
        cin>>arr2[i];
    }

    int res[m+n];

    // Merges Array
    mergeArray(arr1,arr2,n,m,res);

    sortArray(res,m,n);
    
    for(int i=0; i<m+n; i++){
        cout<<res[i]<<" ";
    }
    return 0;
}

//USING WHILE LOOP 

//    int i=0,j=0,k=0;
//    while(i<m){ //traversing for array 1
//    res[k]=arr1[i];
//    i++,k++;
//    }

//    while(j<n){//traversing for array 2
//     res[k]=arr2[j];
//     k++,j++;
//    }

//    for(int i=0; i<m+n; i++){
//     cout<<res[i]<<" ";
//    }