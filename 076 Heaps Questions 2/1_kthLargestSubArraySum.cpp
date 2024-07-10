/*
APPROACH 1 
* calculate sum of all subarrays , and store in a vector - O(N^2)
* sort - O(N^2 LOG N)
SC - O(N^2)

APPROACH 2 - PRIORITY QUEUE MIN HEAP
TC - O(N^2)
SC - O(K)
*/

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int kthLargest_1(vector<int>& arr, int n, int k) {

    vector<int> sumStore;
    for(int i = 0; i<n; i++) {
        int sum = 0;
        for(int j = i; j<n; j++) {
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }

    sort(sumStore.begin() , sumStore.end());
    return sumStore[sumStore.size() - k];
}

int kthLargest_2(vector<int>& arr, int n, int k) {

    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i<n; i++) {
        int sum = 0;
        for(int j = i; j<n; j++) {
            sum += arr[j];
            if(pq.size() < k) {
                pq.push(sum);
            }
            else {
                if(sum > pq.top()) {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();    
}

int main()
{
    int n = 5;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 3;

    // cout << kthLargest_1(arr, n, k);
    cout << kthLargest_2(arr, n, k);

    return 0;
}