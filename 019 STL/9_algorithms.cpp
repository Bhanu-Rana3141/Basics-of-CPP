#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
min, max, swap, reverse, sort, rotate, binary search
*/

int main() {

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout << "3 present or not : " << binary_search(v.begin(), v.end(), 3) << endl;

    // Rotate
    cout << "rotate: ";
    rotate(v.begin(), v.begin()+2, v.end());
    // rotate(v.begin(), v.end()-2, v.end());
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // string reverse
    string s = "abcd";
    cout << s << endl;
    reverse(s.begin(), s.end());
    cout << s;

    // sort(v.begin(), v.end()) -> based on introsort, made by combination of quick, heap, insertion sort
    


    return 0;
}