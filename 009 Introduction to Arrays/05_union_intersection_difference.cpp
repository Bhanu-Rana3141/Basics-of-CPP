#include<iostream>
using namespace std;

int main () {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr1[n];
    for(int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    int m;
    cout << "Enter m: ";
    cin >> m;

    int arr2[m];
    for(int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    int choice = 0;
    cout << "Enter choice: ";
    cin >> choice;

    for(int i = 0; i < n; i++) {
        if(choice == 1) {
            for(int j = 0; j < m; j++) {
                arr1[j] = -1;
            }
        }

        else if(choice == 2) {
            for(int j=0; j<m; j++) {
                if(arr1[i] == arr2[j]) {
                    cout << arr1[i] << " ";
                    break;
                }
            }
        }

        else if(choice == 3) {
            for(int j=0; j<m; j++) {
                if(arr1[i] == arr2[j]) {
                    arr1[i] = -1;
                    break;
                }
            }
        }
    }


    if(choice == 1) {
        for(int i=0; i<n; i++) {
            cout << arr1[i] << " ";
        }

        for(int j=0; j<m; j++) {
            if(arr2[j] != -1) {
                cout << arr2[j] << " ";
            }
        }
    }

    return 0;
}