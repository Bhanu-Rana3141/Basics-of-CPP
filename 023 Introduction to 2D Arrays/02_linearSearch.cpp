#include<iostream>
using namespace std;

void printArray(int arr[][4], int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }cout<<endl;
}

int isPresent(int arr[][4],int target ,int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
           if(arr[i][j] == target){
            return 1;
           }
        }
    }cout<<endl;
}

int main() {

    int arr[3][4];
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cin>>arr[i][j];
        }
    }

    printArray(arr,3,4);

    int target;
    cout<<"Enter target: ";
    cin>>target;

    if(isPresent(arr,target,3,4) == 1){
        cout<<"element found";
    }else{
        cout<<"Not found";
    }

    return 0;
}