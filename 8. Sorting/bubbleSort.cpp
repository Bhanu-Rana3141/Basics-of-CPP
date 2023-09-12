#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int sortArr(int arr[], int n){
    int count = 0;
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                count++;
            }
        }
    }
    return count;
}

void optimised_sort(int arr[], int n){
     for(int i=1; i<n; i++){
        bool flag = false;

        for(int j=0; j<n-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = true;
            }
        }
        if(flag == false){
            break;  // already sorted
        }
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

    int ans =  sortArr(arr,n);   // time complexity -> O(n^2)
    printArray(arr,n);
    cout<<"Ans: "<<ans;
    optimised_sort(arr,n); // time complexity -> O(n)
 

    
    return 0;
}