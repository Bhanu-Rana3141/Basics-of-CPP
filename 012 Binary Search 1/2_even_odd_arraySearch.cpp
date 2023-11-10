#include<iostream>
using namespace std;

int binarySearch(int *arr, int size, int key){
    int start = 0;
    int end = size-1;
    int mid = start+(end-start)/2;

    while(start <= end){
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int main() {
    
    int even[6] = {2,4,6,8,12,18};
    int odd[5] = {3,8,11,14,16};

    int key;
    cout << "Enter key: ";
    cin >> key;

    int even_index = binarySearch(even,6,key);
    cout << "Key found at index in even array: " << even_index << endl;

    int odd_index = binarySearch(odd,5,key);
    cout << "key found at index in odd array: " << odd_index;
    
    return 0;
}