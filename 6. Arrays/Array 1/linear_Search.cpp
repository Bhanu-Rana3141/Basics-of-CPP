#include<iostream>
using namespace std;


int main() {
    int array[5];
    int size = sizeof(array)/sizeof(array[0]);
    cout<<"Size of array: "<<size<<endl;

    cout<<"Enter elements of array: ";
    for(int i=0; i<size; i++){
        cin>>array[i];
    }

    int key;
    cout<<"Enter key ele: ";
    cin>>key;

    int ans=-1;
    
    for(int i=0; i<size; i++){
        if(array[i] == key){
            ans=i;
            break;
        }
    }

    cout<<"element present at index: "<<ans;
    

    return 0;
}