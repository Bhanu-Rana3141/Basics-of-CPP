#include<iostream>
using namespace std;

int countPairs(int arr[] , int size,int x){
    int count=0;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i] + arr[j] == x){
                count++;
            }
        }
    }
    return count;
}

void print_pairs(int arr[] , int n, int target_sum){
    int i=0,j=n-1;
    while(i<j){
        if(arr[i] + arr[j] == target_sum){
            cout<<arr[i]<<","<<arr[j]<<endl;
        }
        j--;
        if(j==i){
            i++,j=n-1;
        }
    }
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

    int target_sum;
    cout<<"Enter target: ";
    cin>>target_sum;

    int count = countPairs(arr,n,target_sum);
    cout<<"\nTotal pairs: "<<count<<endl;

    print_pairs(arr,n,target_sum);
    return 0;
}