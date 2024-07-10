#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {

    int left = 2*i + 1;
    int right = 2*i + 2;
    int largest = i;

    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if(largest != i) {
        swap(arr[i] , arr[largest]);
        heapify(arr, n, largest);
    }
}

int main()
{
    int n = 4;
    int m = 3;

    int arr1[] = {10 , 5, 6, 2};
    int arr2[] = {12, 7, 9};

    vector<int> ans;
    for(int i = 0; i<n; i++) {
        ans.push_back(arr1[i]);
    }

    for(int i = 0; i<m; i++) {
        ans.push_back(arr2[i]);
    }

    for(int i = ans.size()/2; i>=0; i--) {
        heapify(ans, ans.size(), i);
    }

    for(int i = 0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}