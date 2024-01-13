/*
Edge case : if 0 is present at first position(src) and last position(destination) of matrix in that case no path exists
1. creating a 2-D matrix which will have 1 at its starting pos and at last pos
2. creating another matrix to track the position, where rat has visited and should not visit again
3. rat can move down, left, right, up on basis of 3 condititons :
* indexes if i and j should not be out of bound
* the direction rat is visiting should be 1 in orignal matrix and true has to be marked in visiting matrix
4. After reaching destination, find all other ways to reach destination use BACKTRACKING
*/

#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>>& arr, int i, int j, int row, int col, vector<vector<bool>>& visited) {
    if(((i>=0 && i<row) && (j>=0 && j<col)) && (arr[i][j] == 1) && (visited[i][j] == false)) {
        return true;
    }
    else{
        return false;
    }
}   

void solve(vector<vector<int>>&arr, int row, int col, int i, int j, vector<vector<bool>>& visited, vector<string>&path, string output) {
    // base case - if reached at destination
    if(i == row-1 && j == col-1) {
        path.push_back(output);
        return;
    }
    
    // down
    if(isSafe(arr, i+1, j, row, col, visited)) {
        visited[i][j] = true;
        solve(arr, row, col, i+1, j, visited, path, output+'D');
        // backtrack
        visited[i+1][j] = false;
    }

    // left
    if(isSafe(arr, i, j-1, row, col, visited)) {
        visited[i][j] = true;
        solve(arr, row, col, i, j-1, visited, path, output+'L');
        // backtrack
        visited[i][j-1] = false;
    }

    // right
    if(isSafe(arr, i, j+1, row, col, visited)) {
        visited[i][j] = true;
        solve(arr, row, col, i, j+1, visited, path, output+'R');
        // backtrack
        visited[i][j+1] = false;
    }

    // up
    if(isSafe(arr, i-1, j, row, col, visited)) {
        visited[i][j] = true;
        solve(arr, row, col, i-1, j, visited, path, output+'U');
        // backtrack
        visited[i-1][j] = false;
    }
}

int main() {

    int row;
    cout << "Enter row: ";
    cin >> row;

    int col; 
    cout << "Enter col: ";
    cin >> col;

    vector<vector<int>> maze(row, vector<int>(col));
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin >> maze[i][j];
        }
    }

    if(maze[0][0] == 0) {
        cout << "path does not exits";
        return 0;
    }

    // to check visiting 
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    // value of src
    visited[0][0] = true;

    vector<string>path;
    string output = "";

    solve(maze, row, col, 0, 0, visited, path, output);
    
    if(path.size() == 0) {
        cout << "Not exists";
        return 0;
    }

    cout << "printing all possible ways: ";
    for(auto it : path) {
        cout << it << " ";
    }

    return 0;
}