/*
 * Every element is unique
 * implementation is done using BST
 * element can only be inserted or deleted, therefore it can't be modified
 * elements are returned in sorted order
 
 * ORDERED SET -> 1.slow , 2. elements comes in sorted order
 * UNORDERED   -> 1. Fast, 2. elements comes in random order
 
 * insert, count, erase, find -> TC: O(logn) 
*/

#include<iostream>
#include<set>
using namespace std;

int main() {
    
    set<int> s;
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(6);
    s.insert(0);
    s.insert(0);
    s.insert(0);
    s.insert(10);
    s.insert(20);
    s.insert(40);

    cout << "size: " << s.size() << endl;
    cout << "all values: ";
    for(int i : s) {
        cout << i << " ";
    }
    cout << endl;

    // 1. erase 
    s.erase(s.begin());
    cout << "values after erasing 0th element: ";
    for(int i : s) {
        cout << i << " ";
    }
    cout << endl;

    // creating an iterator for traversing
    set<int>::iterator it = s.begin();
    it++; // pointing to index 1
    s.erase(it);
    cout << "values after erasing 1st element: ";
    for(int i : s) {
        cout << i << " ";
    }
    cout << endl << endl;


    // 2. count -> checks whether element is present or not
    
    cout << "element present or not: " << s.count(5) << endl;
   
    // 3. find 
    set<int>:: iterator itr = s.find(6); // jo value find m likhi hogi including that, uske aage ki bhi saari values print hongi
    for(auto i=itr; i!=s.end(); i++) {
        cout << *i << " ";
    }
    

    return 0;
}

