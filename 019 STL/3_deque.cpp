/* Doubly ended queue  -> different fixed size static arrays are used to implement it
    *starting and ending pe insertion/deletion operations perform kr skte hain
    * Dynamic
*/

#include<iostream>
#include<deque>
using namespace std;

void print(deque<int>&d) {
    for(int i=0; i<d.size(); i++) {
        cout << d[i] << " ";
    }
    cout << endl;
}


int main() {

    deque<int> a(5,1);
    deque<int> b(a);
    deque<int> c = {1,2,3,4,5};
     
    cout << "a: ";
    print(a);
    cout << "b: ";
    print(b); 
    cout << "c: ";
    print(c);

    cout << endl;

    deque<int> d;
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