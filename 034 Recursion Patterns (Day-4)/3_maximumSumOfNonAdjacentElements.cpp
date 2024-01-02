#include<iostream>
#include<limits.h>
using namespace std;

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    pair<int, int> p;
    int ans = INT_MIN;

    for(int i=0; i<n; i++) {
        for(int j=i+2; j<n; j++) {
            int sum = arr[i] + arr[j];
            if(sum > ans) {
                ans = sum;
                p = {arr[i], arr[j]};
            }
        }
    }
    
    cout << "Pairs: {" << p.first << ", " << p.second << "} , " << "Max sum : " << ans;

    return 0;
}