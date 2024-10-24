/*

Q. What is Heap? 
- heap is a data structure that is a complete binary tree that comes with heap order property
- Heaps are usually used to implement priority queues, where the smallest (or largest) element is always at the root of the tree.

Q. What is complete binary tree ?
- a tree in which all levels are completely filled except last level, last level is not mandatory to be filled
- node always added from left 

TYPES OF HEAP
* HEAP ORDER PROPERTY - 
- Max heap - child value will be small than its parent
- Min heap - every node value will be small then it's children value

Q. why in heapify function traversal is started from n/2 -1 -> 0 not from 0 -> n/2
-> efficiency , no redundancy

leaf node in Complete binary tree lies from n/2 + 1 -> n , and leaf node can be considered as heap , single node no need to compare , so the nodes from 0 -> n/2 have to be placed at their right position
*/

#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int leftIdx = 2*i + 1;
    int rightIdx = 2*i + 2;

    if(leftIdx < n && arr[largest] < arr[leftIdx]) {
        largest = leftIdx;
    }
    else if(rightIdx < n && arr[largest] < arr[rightIdx]) {
        largest = rightIdx;
    }
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{
    vector<int> arr = {54, 53, 55, 52, 50};
    int n = arr.size();

    for(int i = n/2; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}