#include <iostream>
#include<vector>
using namespace std;

void printArray(vector<int>&arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }cout << endl;
}


int main() {
    int n;
    cout << "Ente n : ";
    cin >> n;

    cout << "v1 elements: ";
    vector<int>v1(n);
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }

    cout << "v2 elements: ";
    vector<int>v2(n);
    for (int i = 0; i < n; i++) {
        cin >> v2[i];
    }

    swap(v1,v2);

    cout << "v1: ";
    printArray(v1);
    cout << "v2: ";
    printArray(v2);

   

    return 0;
}
