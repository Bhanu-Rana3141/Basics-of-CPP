/*  1. jb 1 vector pura fill hojayega, phir ye 1 purane wale se double size ka vector create karega and then purane wala naye m copy hojayaga and purane wala dead hojayaga
    2. Dynamic - size can be changed

    *size -> kitne elements stored hain
    *capacity -> total kitne elements k liye memory allocate hui h i.e kitne elements store kr skte hain
*/

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>&v) {
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {

    vector<int> a(5,1);
    vector<int> b(a); // copying b in a
    vector<int> c = {1,2,3,4,5};

    cout << "a: ";
    print(a);

    cout << "b: ";
    print(b);

    cout << "c: ";
    print(c);

    cout << endl;

    vector<int> v;
    
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
   
    v.push_back(1);
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    v.push_back(2);
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    v.push_back(3);
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    cout << endl;

    cout << "Before pop: ";
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    v.pop_back();

    cout << "After pop: ";
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << endl;

    cout << "Before clear: ";
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    v.clear(); // size will become 0, but capacity will remain same
    cout << "After clear: ";
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    return 0;
}