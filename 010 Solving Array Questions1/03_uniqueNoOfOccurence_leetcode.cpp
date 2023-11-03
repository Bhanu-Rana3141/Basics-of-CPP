#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* Approach 
1. count frequency of each element and store in new vector i.e ans (TC -> O(N^2))
2. sort ans vector (TC-> O(n log n))
3. check if duplicates are present, if present then return false, else return true   (TC -> O(n))
*/

int main() {
    int n;
    cout << "Enter the n of the array: ";
    cin >> n;

    vector<int>arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int>ans;

    for(int i=0; i<n; i++){
        if(arr[i] == 'a') {
            continue;
        }
        int count=1;
        for(int j=i+1; j<n; j++){
            if(arr[i] == arr[j]){
                count++;
                arr[j] = 'a';
            }
        }
        ans.push_back(count);
    }
    
    sort(ans.begin(), ans.end());
 
    for(int i=1; i<ans.size(); i++) {
        if(ans[i] == ans[i-1]) {
            cout << "False";
            return 0;
        }
    }
    cout << "true";
    
    return 0;
}