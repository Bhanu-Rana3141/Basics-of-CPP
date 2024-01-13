#include<iostream>
#include<vector>
using namespace std;

void printSolution(vector<vector<char>>& board, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
}

bool isSafe(vector<vector<char>>& board, int row, int col, int n) {
    // check row
    int i = row;
    int j = col;
    while(j >= 0) {
        if(board[i][j] == 'Q') {
            return false;
        }
        j--;
    }

    // check upper left diagonal
    i = row;
    j = col;
    while(i >= 0 && j >= 0) {
        if(board[i][j] == 'Q') {
            return false;
        }
        i--;
        j--;
    }

    // check lower left diagonal
    i = row;
    j = col;
    while(i<n && j>=0) {
        if(board[i][j] == 'Q') {
            return false;
        }
        i++;
        j--;
    }

    // Q is not found at any position which means it is safe to place Q
    return true;
}

void solve(vector<vector<char>> board, int col, int n) {
    // base case
    if(col >= n) {
        printSolution(board, n);
        return;
    } 

    // 1 case - try to place Q in each row
    for(int row=0; row<n; row++) {
        if(isSafe(board, row, col, n)) {
            // place queen
            board[row][col] = 'Q';
        }
        // recursion call
        solve(board, col+1, n);

        // backtracking
        board[row][col] = '.';
    }
}

int main() {
    
   int n = 4;
   vector<vector<char>> board(n, vector<char>(n,'.'));
   int col = 0;
   solve(board, col, n);


    return 0;
}