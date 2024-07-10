#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;

    int n = 4;
    int arr[] = {4, 3, 2, 6};

    for(int i = 0; i<n; i++) {
        pq.push(arr[i]);
    }

    while(pq.size() > 1) {
        int ele1 = pq.top();
        pq.pop();

        int ele2 = pq.top();
        pq.pop();

        int sum = ele1 + ele2;
        ans += sum;
        pq.push(sum);
    }

    cout << ans;

    return 0;
}