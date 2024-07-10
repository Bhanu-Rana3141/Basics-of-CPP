#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int n = 6;
    int arr[] = {6,3,5,1,0,4};

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i<n; i++) {
        pq.push(arr[i]);
    }

    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}