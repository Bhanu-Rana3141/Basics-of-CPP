/*
APPROACH 1 
TC - O(N*K)

APPROACH 2
TC - O(N * LOG N)

APPROACH 3
- create a max heap for 1st k elements
- for rest k -> n-1 elements , if element < heap.top() -> heap.pop() , heap.push(element)
- heap will left with k smallest elements
- heap top will be the kth smallest element
*/

#include<iostream>
#include<limits.h> 
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int kthSmallest_1(vector<int>& arr, int n) {

    int smallest = INT_MAX;
    int idx = -1;

    for(int i=0; i<n; i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
            idx = i;
        }
    }

    arr[idx] = INT_MAX;
    return smallest;
}

int kthSmallest_2(vector<int>& arr, int& n, int& k) {

    sort(arr.begin(), arr.end());
    return arr[k-1];
}

int kthSmallest_3(vector<int>& arr, int n, int k) {

    priority_queue<int> pq;

    for(int i=0; i<k; i++) {
        pq.push(arr[i]);
    }

    for(int i=k; i<n; i++) {
        if(arr[i] < pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
}

int main()
{
    
    int n = 5;
    vector<int> arr = {7, 10, 4, 20, 15};

    int k = 3;

    if(k == n) {
        cout << "does not exist" << endl;
    }

    // int ans = -1;
    // for(int i=0; i<k; i++) {
    //     ans = kthSmallest_1(arr, n);
    // }
    
    // int ans = kthSmallest_2(arr, n, k);
    int ans = kthSmallest_3(arr, n, k);

    cout << "ans : " << ans;

    return 0;
}