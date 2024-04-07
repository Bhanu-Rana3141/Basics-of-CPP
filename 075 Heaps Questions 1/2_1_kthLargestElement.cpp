/*

TC:

The first loop iterates k times, where k is the parameter passed to the function. So, it has a time complexity of O(k).
The second loop iterates from index k to n-1, where n is the size of the input array arr. So, it iterates n-k times.
Inside the second loop, the operations are constant time: pushing and popping elements from the priority queue (pq), which has a maximum size of k.
The time complexity of pushing and popping elements from a priority queue of size k is O(log k) for each operation.
Hence, the overall time complexity is O(k + (n - k) * log k), which can be simplified to O(n * log k), assuming k is significantly smaller than n.

SC - O(K)
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int kthLargest(vector<int> &arr, int n, int k) {

    priority_queue<int, vector<int>, greater<int>> pq;

    // O(K)
    for(int i=0; i<k; i++) {
        pq.push(arr[i]);
    }

    // O(N-K)*(LOG K)
    for(int i=k; i<n; i++) {
        if(arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int main()
{
    
    int n = 5;
    vector<int> arr = {7, 10, 4, 20, 15};
    int k = 3;

    cout << "ans : " << kthLargest(arr, n, k);

    return 0;
}