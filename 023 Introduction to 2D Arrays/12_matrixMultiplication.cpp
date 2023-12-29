#include<iostream>
using namespace std;

int main() {

    int r1,c1;
    cout << "Enter r1: ";
    cin >> r1;
    cout << "Enter c1: ";
    cin >> c1;

    int arr1[r1][c1];
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c1; j++) {
            cin >> arr1[i][j];
        }
    }

    int r2,c2;
    cout << "Enter r2: ";
    cin >> r2;
    cout << "Enter c2: ";
    cin >> c2;

    int arr2[r2][c2];
    for(int i=0; i<r2; i++) {
        for(int j=0; j<c2; j++) {
            cin >> arr2[i][j];
        }
    }

    if(c1 != r2) {
        cout << "matrix multiplication not possible";
    }
    else{
        int C[r1][c2];
        for(int i=0; i<r1; i++) {
            for(int j=0; j<c2; j++) {
                C[i][j] = 0;
                for(int k=0; k<r2; k++) {
                    C[i][j] += arr1[i][k]*arr2[k][j];
                }
            }
        }

        for(int i=0; i<r1; i++) {
            for(int j=0; j<c2; j++) {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}