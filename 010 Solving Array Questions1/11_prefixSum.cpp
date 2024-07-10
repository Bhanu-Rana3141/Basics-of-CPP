#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>& arr , int n) {

    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    print(arr, n);
    for(int i = 1; i<n; i++) {
        arr[i] += arr[i-1];
    }
    print(arr, n);

    return 0;
}