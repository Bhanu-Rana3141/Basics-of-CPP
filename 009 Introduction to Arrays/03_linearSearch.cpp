#include<iostream>
using namespace std;

bool linearSearch(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        if(arr[i] == key){
            return true;
        }
    }
    return false;
}

int main() {

    int n;         
    cout<<"Enter n: ";
    cin>>n;


    int arr[n]; // bad practice
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

   int key;
   cout<<"Enter key: ";
   cin>>key;

    bool found = linearSearch(arr,n,key);

    if(found){
        cout<<"Key is present";
    }
    else{
        cout<<"key is not present";
    }
}