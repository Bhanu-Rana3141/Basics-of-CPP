#include<iostream>
using namespace std;

int firstOccurence(int arr[],int n,int key){
    int start = 0;
    int end = n-1;
    int mid = start+(end-start)/2;

    int ans = -1;
    while(start<=end){
        if(arr[mid] == key){
            ans = mid;
            end = mid-1;
        }
        else if(arr[mid]>key){
            end = mid-1;
        }
        else if(arr[mid]<key){
            start = mid+1;
        }
        mid = start+(end-start)/2;
    }
    return ans;
}

int lastOccurence(int arr[] , int n , int key){
    int start = 0;
    int end = n-1;
    int mid = start+(end-start)/2;
    int ans = -1;

    while(start<=end){
        if(arr[mid] == key){
            ans = mid;
            start = mid+1;
        }
        else if(arr[mid] > key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start+(end-start)/2;
    }
    return ans;
}


int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];
    cout<<"Enter array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int key;
    cout << "Enter key: ";
    cin >> key;


    /* Can be solved by Linear Search approach, by using 2 for loops 1 for first occurence and second for last occurence]
    TIME COMPLEXITY - o(n)

    //First Occurence  -> Iterating from 0th element
    for(int i=0; i<n; i++){
        if(arr[i] == key){
            cout << i;
            break;
        }
    }


    //last Occurence  -. Iterating from n-1 element
    for(int i=n-1; i>=0; i--){
        if(arr[i] == key){
            cout << i;
            break;
        }
    }

    */


    // USING BINARY SEARCH  -> TC : O(log n)
    int start = firstOccurence(arr,n,key);
    int last = lastOccurence(arr,n,key);

    cout << "first: " << start << endl << "last : " << last;
    

}