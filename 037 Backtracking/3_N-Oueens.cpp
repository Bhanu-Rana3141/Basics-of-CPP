#include<iostream>
#include<vector>
using namespace std;

void printSolution(vector<vector<char>>& board, int n, vector<vector<string>>& ans) {
    vector<string> temp;
    for(int i=0; i<n; i++) {
        string output = "";
        for(int j=0; j<n; j++) {
            output.push_back(board[i][j]);
        }
        temp.push_back(output);
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<char>>& board, int n) {
    // checking if queen could be placed in current cell by checking in left direction
    int i = row;
    int j = col;

    while(j >= 0) {
        if(board[i][j] == 'Q') {
            return false;
        }
        j--;
    }

    // checking upper left diagonal
    i = row;
    j = col;
    while(i >= 0 && j >= 0) {
        if(board[i][j] == 'Q') {
            return false;
        }
        i--, j--;
    }

    // checking bottom left diagonal
    i = row;
    j = col;
    while(i < n && j >= 0) {
        if(board[i][j] == 'Q') {
            return false;
        }
        i++, j--;
    }
    
    // if no queen is present in all the directions checked above, then queen can be placed at current cell
    return true;
}

void solve(vector<vector<char>>& board, int col ,int n, vector<vector<string>>& ans) {
    // base case
    if(col >= n) {
        printSolution(board, n, ans);
        return;
    }

    // Place queen in each row
    for(int row=0; row<n; row++) {
        if(isSafe(row, col, board, n)) {
            // queen placed
            board[row][col] = 'Q';
            // recursive call for other col's
            solve(board, col+1, n, ans);
            // backtracking
            board[row][col] = '.';
        }
    }
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n,'.'));
    int col = 0;

    vector<vector<string>> ans;

    solve(board, col, n, ans);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}