/*
    *cout << l[i] is not done,  you don't have random access to elements using an index like you do with    arrays or vectors. Instead, you typically use iterators to traverse through the elements.
    * implementation done with doubly linked list
*/

#include<iostream>
#include<list>
using namespace std;

void print(list<int>&l) {
    // This is a range-based for loop, and int i is a loop variable that takes on the value of each element in the range of the container l in each iteration. The loop automatically iterates over all elements in the container, and you don't need to worry about indices or iterators explicitly.
    for(int i : l) {
        cout << i << " ";
    }
    cout << endl;
}


int main() {

    list<int> a(5,1);
    list<int> b(a);
    list<int> c = {1,2,3,4,5};
     
    cout << "a: ";
    print(a);
    cout << "b: ";
    print(b); 
    cout << "c: ";
    print(c);

    cout << endl;

    list<int> d;
    d.push_back(15);
    d.push_back(16);
    d.push_back(5);
    d.push_front(10);

    print(d);

    cout << "front: " << d.front() << endl;
    cout << "back: " << d.back() << endl;
    cout << "erase: ";
    d.erase(d.begin());
    print(d);

    return 0;
}