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
*/