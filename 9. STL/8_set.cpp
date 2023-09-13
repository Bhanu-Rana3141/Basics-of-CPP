#include<iostream>
#include<set>
using namespace std;

int main() {
    set<int> s;
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(0);

    for(int i : s){
        cout<<i<<" ";
    }cout<<endl;

    // Iterator
    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);

    for(int i : s){
        cout<<i<<" ";
    }cout<<endl;

    // count -> tells ele present or not

    cout<<"5 present or not -> "<<s.count(5);
    return 0;
}
