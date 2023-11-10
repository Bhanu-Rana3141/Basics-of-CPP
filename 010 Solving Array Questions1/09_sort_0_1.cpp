#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArray(vector<int>arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int>arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    printArray(arr);
    cout<<endl;

/*  Approach 1 -> use SORT -> TC : O(n logn)
    sort(arr.begin(),arr.end());
    printArray(arr);
*/

/*  Approach 2 -> count no of 0's and place 0's at beginning    -> TC : O(n)
    int zeroCount=0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0) {
            zeroCount++;
        }
    }

    for(int i=0; i<n; i++){
        if(i<zeroCount){
            arr[i] = 0;
        }
        else{
            arr[i] = 1;
        }
    }
    printArray(arr);
*/

//  Approach 3 -> 2 pointer   -. TC : O(n)
    int i=0,j=n-1;
    while(i<j){
        if(arr[i] != 0 && arr[j] == 0){
            swap(arr[i] , arr[j]);
            i++, j--;
        }
        if(arr[i] == 0){
            i++;
        }
        if(arr[j] != 0){
            j--;
        }
    }
    printArray(arr);
    return 0;
}
