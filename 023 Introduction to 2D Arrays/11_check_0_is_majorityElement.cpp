#include<iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int m;
    cout << "Enter m: ";
    cin >> m;

    int arr[n][m];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << endl;

    int total_elements = n*m;

    int count = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j] == 0) {
                count ++;
            }
        }
    }

    cout << "zero count : " << count << endl;

    if(count > (total_elements/2)){
        cout << "Yes 0 is majority element";
    }
    else{
        cout << "No, 0 is not majority element";
    }
    return 0;
}