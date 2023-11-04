#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArray(vector<int>&arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int ArrayToIntConversion(vector<int>&arr, int size) {
    int value = 0;
    for(int i = 0; i < size; i++) {
        int x = arr[i] % 10;
        value = value * 10 + x;
    }
    return value;
}

void intToArrayConversion(vector<int>&arr, int sum) {

    while(sum > 0) {
        int x = sum % 10;
        arr.push_back(x);
        sum /= 10;
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter arr1 elements: ";
    vector<int>arr1(n);
    for(int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    int m;
    cout << "Enter m: ";
    cin >> m;

    cout << "Enter arr2 elements: ";
    vector<int>arr2(m);
    for(int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    int arr1_to_int = ArrayToIntConversion(arr1,n);
    int arr2_to_int = ArrayToIntConversion(arr2,m);

    int sum = arr1_to_int + arr2_to_int ;

    cout << "arr1 to integer : " << arr1_to_int << endl;
    cout << "arr2 to integer : " << arr2_to_int << endl;
    cout << "Sum : " << sum << endl;

    vector<int>ans;
    intToArrayConversion(ans, sum);

    printArray(ans);

    reverse(ans.begin(), ans.end());

    printArray(ans);
    
    return 0;
}