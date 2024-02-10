#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> arr, int n, int mid, int m) {

    int pageSum = 0;
    int studentCnt = 1;

    for(int i=0; i<n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else {
            studentCnt++;
            if(studentCnt > m || arr[i] > mid) {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int main() {

    vector<int> arr = {10, 20, 30, 40};
    int m = 2;

    int n = arr.size();

    int s = 0;
    
    int sum  = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }

    int e = sum;

    int ans = -1;

    while(s <= e) {

        int mid = s + (e - s) / 2;

        if(isPossible(arr, n, mid, m)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }

    cout << "Ans: " << ans;
    
    return 0;
}