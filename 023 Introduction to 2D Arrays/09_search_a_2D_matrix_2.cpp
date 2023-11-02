#include<iostream>
#include<vector>
using namespace std;

/*Binary search in each row (Function Declaration)
bool binary_search(int arr[], int target, int m){

    int s=0;
    int e=m-1;
    int mid = s+(e-s)/2;

    while(s<=e) {
        if(arr[mid] == target) {
            return true;
        }
        else if(arr[mid] > target) {
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid = s+(e-s)/2;
    }
    return false;
}
*/

int main() {

    int n; //row size;
    cout<<"Enter row size: ";
    cin>>n;

    int m; //col size
    cout<<"Enter col size: ";
    cin>>m;

    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    cout << endl;

    int target;
    cout<<"Enter target: ";
    cin>>target;

/*Approach 1 :  Brute Force Approach ->  linear search --> O(m*n)
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j] == target) {
                cout<<"true";
                return 0;
            }
        }
    }
    cout<<"False";
*/
   
/*Approach 2 :  Better Aproach -> Using Binary Search in each row as all the rows are sorted
    int ans = -1;
    for(int i=0; i<n; i++) {
       ans = binary_search(arr[i] , target, m);
       if(ans == 1) {
        cout<<"true";
        return 0;
        }
    }
    cout<<"false";
 */

// Approach 3: Optimal Solution -> Using sorted rows and cols

    int rowIndex=0;
    int colIndex = m-1;
    bool flag = false;

    while(rowIndex<n && colIndex>=0) {
        int element = arr[rowIndex][colIndex];
        if(element == target){
            flag = true;
        }
        else if(element<target) {
            rowIndex++;
        }
        else{
            colIndex++;
        }
    }

    flag == true ? cout << true : cout << false;

    return 0;
}