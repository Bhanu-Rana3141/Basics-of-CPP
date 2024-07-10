#include<iostream>
using namespace std;

int main()
{   
    int n = 5;
    int arr[] = {6, 2, 4, 3, 1};

    int totalSum = 0;
    for(int i = 0; i<n; i++) {
        totalSum += arr[i];
    }

    int prefixSum = 0;
    int suffixSum = 0;
    bool isEqual = false;
    for(int i = 0; i<n; i++) {
        prefixSum += arr[i];
        suffixSum = totalSum - prefixSum;

        if(prefixSum == suffixSum) {
            cout << "Equal";
            isEqual = true;
            break;
        }
    }

    if(!isEqual) cout << "false";

    return 0;
}