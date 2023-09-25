#include<iostream>
#include<vector>
using namespace std;

void printArr(vector<vector<int>>&arr){
    int n = arr.size();
    int m = arr[0].size();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

/* Row and col function

void row(vector<vector<int>>&arr ,int i, int m){
   // iterate horizontally for rows     TC -> O(m)
   for(int j=0; j<m; j++){
        if(arr[i][j] != 0) {
            arr[i][j] = -1;
        }
   }
    
}

void col(vector<vector<int>>&arr, int j, int n){
    // iterate vertically for cols   TC -> O(n)
    for(int i=0; i<n; i++) {
        if(arr[i][j] != 0) {
            arr[i][j] = -1;
        }
    }
}
*/

int main() {
    int n; // rows
    cout<<"Enter n: ";
    cin>>n;

    int m; //cols
    cout<<"Enter m: ";
    cin>>m;

/* 3 Approaches: 
    1. Brute Force
    2. Better 
    3. Optimal
*/

/* Approach 1 :   // OVERALL :   TC -> O(n*m) * (O(m) + O(n)) * O(n*m)  = O(n*m)*O(m+n)

In this approach we will traverse through each element of matrix and the position where we will encounter 0 we will assign -1 to each
element of that row and column by creating function except at that position where we encountered 0, because the matrix can have 0 at further
positions and if we will assign 0 to all positions directly it will not give desired result .
    
After assingning -1 we will again traverse through the matrix again and replace all -1 with 0
*/

/*
    vector<vector<int>>arr(n,vector<int>(m));
    // Taking Input
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>arr[i][j];
        }
    }cout<<endl;

    // Checking 0 and calling functions      TC-> O(n*m)
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 0){
                row(arr,i,m);
                col(arr,j,n);
            }
        }
    }

    printArr(arr);
    cout<<endl;

    // Now replacing all -1 with 0       TC -> O(n*m)
    for(int i=0; i<n; i++) {      
        for(int j=0; j<m; j++) {
            if(arr[i][j] == -1){
                arr[i][j] = 0;
            }
        }
    }
    printArr(arr);   
*/
   


/*Approach 2 :    O(n)+O(m)+O(m*n)+O(m*n)   -> O(m*n)

Creating 1D array for rows and cols of size n and m and initialize all values as 0 to keep track which row and col 
contains 0,then traverse through matrix and if 0 is encountered at any position, 1 will be marked at that index
of row and col in newly created arrays which specifies that this row or col contains 0.

After this traverse through matrix again and make a condition if any index of row and col have 1, if(row[i]==1 || col[j]==1)
then place 0 at that position in matrix i.e arr[i][j]=0;

*/  
/*  vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>arr[i][j];
        }
    }cout<<endl;
 
   vector<int>row(n,0);   // O(n)
   vector<int>col(m,0);   // O(m)

    for(int i=0; i<n; i++) {        // O(n*m)
        for(int j=0; j<m; j++) {
            if(arr[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            } 
        }
    }

    for(int i=0; i<n; i++) {        // O(n*m)
        for(int j=0; j<m; j++) {
            if(row[i] == 1 || col[j] == 1){
               arr[i][j] = 0;
            }
        }
    }
    printArr(arr);
*/
    return 0;
}