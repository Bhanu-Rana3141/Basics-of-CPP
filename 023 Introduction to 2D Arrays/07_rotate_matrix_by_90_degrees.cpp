#include<iostream>
using namespace std;

void reverse(int arr[], int n) {

    int s = 0;
    int e = n-1;

    while(s < e) {
        swap(arr[s],arr[e]);
        s++ , e--;
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    cout<<endl;
 
    // Transpose of matrix
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
               swap(arr[i][j] , arr[j][i]);
        }   
    }

    cout << "Tranpose of matrix: ";
    cout << endl;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
           cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
     
    cout << endl;

    // Rotating array by 90 degrees
    for(int i=0; i<n; i++) {
        // reverse(arr[i],n);
        int s = 0, e = n-1;
        while(s < e) {
            swap(arr[i][s++], arr[i][e--]);
        } 
    }

    cout << "Rotated Array: ";
    cout << endl;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}