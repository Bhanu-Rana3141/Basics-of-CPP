#include<iostream>
#include<vector>
using namespace std;

// Time complexity -> O(n*m)  

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

    int total = n*m;
    int count = 0;

    vector<int>ans; // to store ans

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = n-1;
    int endingCol = m-1;

    while(count < total) {

        // Print starting Row
        for(int i=startingCol; i<=endingCol && count<total; i++) {
            ans.push_back(arr[startingRow][i]);
            count++;
        }
        startingRow++;

        // print ending col
        for(int i=startingRow; i<=endingRow && count<total; i++) {
            ans.push_back(arr[i][endingCol]);
            count++;
        }
        endingCol--;

        //print end row
        for(int i=endingCol; i>=startingCol && count<total; i--) {
            ans.push_back(arr[endingRow][i]);
            count++;
        }
        endingRow--;

        //print starting col
        for(int i=endingRow; i>=startingRow && count<total; i--) {
            ans.push_back(arr[i][startingCol]);
            count++;
        }
        startingCol++;
    }

     for(int i=0; i<ans.size(); i++) {
            cout<<ans[i]<<" ";
        }cout<<endl;

    cout<<"count: "<<count;
    return 0;
}