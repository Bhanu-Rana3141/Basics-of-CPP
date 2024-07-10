    /*
TC - O(2^n)
SC - O(n)
*/

#include<iostream>
#include<vector>
using namespace std;

int rob(vector<int>& arr, int i) {
    if(i >= arr.size()) {
        return 0;
    }
    int amtOfRob1 = arr[i] + rob(arr, i+2);
    int amtOfRob2 = 0 + rob(arr, i+1);

    return max(amtOfRob1, amtOfRob2); 
}

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ans = rob(arr, 0);
    cout << "maximum amount: " << ans;
    
    return 0;
}