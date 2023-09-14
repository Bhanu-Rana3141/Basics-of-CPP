#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int>&arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n; 

    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // Approach 1 --> Using Brute Force
    
    // Counting no of zeroes present in array
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            count++;
        }
    }

    // Creating new vector (temp) and pushing non-zero elements in it
    vector<int>temp;
    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }

    // Pushing zero in temp at end
    for(int i=0; i<count; i++){
        temp.push_back(0);
    }

    // Copying temp value in arr
    arr = temp;

    printArray(temp);
    cout<<endl;

    //Approach 2 --> Using 2 pointer

    int nonZero=0; 
    for(int j=0; j<arr.size(); j++){
        if(arr[j] != 0){
            swap(arr[j], arr[nonZero]);
            nonZero++;
        }
    }
    printArray(arr);
    return 0;   
}