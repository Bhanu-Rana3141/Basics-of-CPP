#include<iostream>
using namespace std;

int odd_count(int arr[] , int size){
    int oddCount=0;
    for(int i=0; i<size; i++){
        if(arr[i]%2!=0){
            oddCount++;
        }
    }
    return oddCount;
}

int even_count(int arr[] , int size){
    int evenCount = 0;
    for(int i=0; i<size; i++){
        if(arr[i]%2==0){
            evenCount++;
        }
    }
    return evenCount;
}

int main() {
    int array[5];
    int size = sizeof(array)/sizeof(array[0]);
    cout<<"size: "<<size<<endl;

    cout<<"Enter array ele: ";
    for(int i=0; i<size; i++){
        cin>>array[i];
    }

    int odd = odd_count(array,size);
    int even = even_count(array,size);

    cout<<"Odd: "<<odd<<endl;
    cout<<"Even: "<<even;

    return 0;
}