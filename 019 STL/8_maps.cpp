/*  
    * ORDERED MAP
    * IMPLEMENTATION - red black tree or balanced tree, therefore compleexity of operations O(log n)
    * Data is stored in form of key and value
    * keys are unique, points only one value  [1 key -> 1 value]
    
    * UNORDERED MAP  
    *IMPLEMENTATION - hash table, therefore time complexity O(1)
*/

#include<iostream>
#include<map>
using namespace std;

int main() {

    map<int,string> m;

    // here int is key , and string is value

    m[1] = "Bhanu";
    m[11] = "Rana";
    m[5] = "Partap";

    for(auto i : m) {
        cout << i.first << " : " << i.second << endl;
    }

    cout << endl;
    // 1. insert
    m.insert({7, "Singh"});
    cout << "After inserting: " << endl;
    for(auto i : m) {
        cout << i.first << " : " << i.second << endl;
    }

    // 2. count
    cout << endl;
    cout << "present or not : " << m.count(11) << endl;

    cout << endl;

    // 3. erase
    cout << "after erase: " << endl;
    m.erase(7);
    for(auto i : m) {
        cout << i.first << " " << i.second << endl;
    }cout << endl;

    // 4. find -> returns iterator and all the elements after it
    auto it = m.find(5);
    for(auto i=it; i!=m.end(); i++) {
        cout << i->first << endl;
    }
    return 0;
}