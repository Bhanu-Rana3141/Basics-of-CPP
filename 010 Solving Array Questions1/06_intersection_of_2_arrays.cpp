#include <iostream>
#include<vector>
using namespace std;

void printArray(vector<int>arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }cout<<endl;
}

/* Implementation  :  TC -> O(n*m)
void intersection(vector<int>&arr1, int n, vector<int>&arr2, int m,  vector<int>&ans){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr1[i] == arr2[j]){
                ans.push_back(arr1[i]);
                arr2[j] = -1;
                break;
            }
        }
    }
}
*/

/*optimisation 1 -> TLE O(n*m)
void intersection(vector<int>&arr1, int n, vector<int>&arr2, int m,  vector<int>&ans){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr1[i] < arr2[j]){ 
                break;
            }
            else if(arr1[i] == arr2[j]){
                ans.push_back(arr1[i]);
                arr2[j] = -1;
                break;
            }
        }
    }
}
*/

// Optimisation 2 -> O(n+m)
void intersection(vector<int>&arr1, int n, vector<int>&arr2, int m, vector<int>&ans){
    int i=0,j=0;
    while(i<n && j<m){
        if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i++,j++;
        }
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int>arr1(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    int m;
    cout << "Enter m: ";
    cin >> m;

    vector<int>arr2(m);
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    
    cout << "arr1: ";
    printArray(arr1);

    cout << "arr2: ";
    printArray(arr2);

    vector<int>ans;  // to store ans

    intersection(arr1,n,arr2,m,ans);

    printArray(ans);

    return 0;
}
