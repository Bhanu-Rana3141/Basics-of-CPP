#include<iostream>
using namespace std;

bool isPossible(int *arr, int mid, int n, int m ) {

    int painterCount = 1;
    int minTime = 0;

    for(int i=0; i<n; i++) {
        if(minTime + arr[i] <= mid) {
            minTime += arr[i];
        }
        else {
            painterCount++;
            if(painterCount > m || arr[i] > mid) {
                return false;
            }
            minTime = arr[i];
        }
    }
    return true;
}

int main() {

    int n = 6;
    int m = 2;
    int arr[] = {2, 1, 5, 6, 2, 3};

    int s = 0;

    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }

    int e = sum;

    int ans = -1;

    while(s <= e) {
        int mid = s + (e-s)/2;

        if(isPossible(arr, mid, n, m)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }

    cout << "ans: " << ans;
    
    return 0;
}