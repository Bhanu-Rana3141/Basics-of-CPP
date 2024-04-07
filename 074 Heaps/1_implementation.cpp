/*
Implementing USING ARRAY
- 0 index will be empty
- left child = 2*i
- right child = 2*i+1
- parent = i/2

IN 0 BASED INDEXING
- left child = 2*i+1
- right child = 2*i+2
- parent = (i-1)

INSERTION 
- insert node at end in array
- take it to its right postion by comparing its value with its parent 

DELETION - root node will be deleted
- arr[1] = arr[size]
- size -- 
- now place new root node on its right postion by comparing with its left and right children

TC - FOR INSERTION AND DELETION - O(LOG N)


HEAPIFY ALGO - algo used to place a node at it's right position 
- leaf nodes in CBT are from : (n/2 + 1) -> n   , leaf nodes are already a heap and no need to process they are already at its right position
- so , 1 -> n/2 part has to be processed i.e they have to be placed on their right position

*/

#include<iostream>
#include<queue>
using namespace std;

class Heap {

    public:
        int arr[100];
        int size;

    Heap() {
        size = 0;
        arr[0] = -1;
    }

    void insert(int value) {

        size = size + 1;
        int index = size;
        arr[index] = value;

        while(index > 1) 
        {
            int parent = index/2;
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;
            }
        } 
    } 

    void print() {

        for(int i=1; i<=size; i++) {
            cout << arr[i] << " ";
        }
    }

    // jb bhi delete ki baat hogi root node ko delete krna h
    void deleteFromHeap() {

        if(size == 0) {
            cout << "Nothing to delete " << endl;
            return;
        }

        // step 1: put last element at first index
        arr[1] = arr[size];

        // step 2: remove last element
        size--;

        // step 3: take root node to its correct postition
        int i = 1;
        while(i < size) {

            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if(leftIndex <= size && arr[i] < arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex <= size && arr[i] < arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else {
                return;
            }
        }
    }
};

void heapify(int *arr, int n, int i) {

    int largest = i;
    int leftIdx = 2*i;
    int rightIdx = 2*i + 1;

    if(leftIdx <= n && arr[largest] < arr[leftIdx]) {
        largest = leftIdx;
    }
    if(rightIdx <= n && arr[largest] < arr[rightIdx]) {
        largest = rightIdx;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n) {

    int size = n;

    while(size > 1) {

        // step 1: swap
        swap(arr[size], arr[1]);
        size--;

        // step 2 : heapify
        heapify(arr, size, 1);
    }
}

void printArr(int *arr, int n) {

    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();
    cout << endl;

    h.deleteFromHeap();

    h.print();
    cout << endl;

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // heap creation
    for(int i=n/2; i>0; i--) {
        heapify(arr, n, i);
    }

    cout << "printing array after heapify : ";
    printArr(arr, n);

    // heap sort
    heapSort(arr, n);

    cout << "printing arr after heap sort: ";
    printArr(arr, n);
    cout << endl;


    // PRIORITY QUEUE


    cout << "USING PRIORITY QUEUE : " << endl << endl;

    // max heap
    cout << "MAX HEAP: " << endl;
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "top element: " << pq.top() << endl;
    pq.pop();
    cout << "top element: " << pq.top() << endl;
    cout << "size: " << pq.size() << endl;

    if(pq.empty()) {
        cout << "pq is empty" << endl;
    }
    else {
        cout << "pq is not empty" << endl;
    }

    cout << endl;

    // min heap
    cout << "MIN HEAP : " << endl;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);

    cout << "top element: " << minHeap.top() << endl;
    minHeap.pop();
    cout << "top element: " << minHeap.top() << endl;
    cout << "size: " << minHeap.size() << endl;

    if(minHeap.empty()) {
        cout << "pq is empty" << endl;
    }
    else {
        cout << "pq is not empty" << endl;
    }

    return 0;
}