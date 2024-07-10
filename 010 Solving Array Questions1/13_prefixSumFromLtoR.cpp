#include<iostream>
using namespace std;

int main()
{
    int l = 1;
    int r = 3;

    int n = 5;
    int arr[] = {5, 1, 2, 3, 4};

    for(int i = 1; i<n; i++) {
        arr[i] += arr[i-1];
    }

    cout << arr[r] - arr[l-1];

    return 0;
}