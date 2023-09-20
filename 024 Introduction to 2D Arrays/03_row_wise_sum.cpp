#include<iostream>
using namespace std;

int main() {

    cout<<"Enter n: ";
    int n;
    cin>>n;

    cout<<"Enter m: ";
    int m;
    cin>>m;

    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    // Row wise sum
    cout<< "Row wise sum: "<<endl;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<m; j++) {
            sum += arr[i][j];
        }
        cout<<"Row "<<i<<" : "<<sum<<endl;
    }

    cout<<endl;
    // Column wise sum
    cout<<"Column wise sum: "<<endl;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<m; j++) {
            sum += arr[j][i];
        }
        cout<<"Col "<<i<<" : "<<sum<<endl;
    }
    return 0;
}