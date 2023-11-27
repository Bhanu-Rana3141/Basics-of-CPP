#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArray(vector<int>arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int>arr(n); 

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Steps to rotate: ";
    cin >> k;

    k = k % n;

    // APPROACH 1
    rotate(arr.begin(), arr.end()-k, arr.end());

    printArray(arr,n);

    

/*  APPROACH 2
    reverse(arr.begin(), arr.end());
    printArray(arr, n);

    reverse(arr.begin(), arr.end()+k);
    printArray(arr,n);
    
    reverse(arr.begin()+k, arr.end());
    printArray(arr,n);
*/
   
 
    return 0;
}
