#include<iostream>
#include<utility>
using namespace std;

int main() {

    pair<int,int> p = {1,3};

    cout << p.first << " " << p.second << endl;

    pair<int,int> a = {5,6};
    cout << a.first << " " << a.second << endl;

    pair<int,pair<int,int>> d = {1,{3,4}};
    cout << d.first << " " << d.second.first << " " << d.second.second;

   

    return 0;
}