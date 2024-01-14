#include<iostream>
#include<array>
using namespace std;

// STL Array is based on simple array, and it is static that's why it is not used in CP

int main() {
    
    array<int,4> a = {1,2,3,4};

    for(int i=0; i<a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "element at index 2: " << a.at(2) << endl;
    cout << "first element: " << a.front() << endl;
    cout << "last element: " << a.back() << endl;
    cout << "empty or not " << a.empty();

    return 0;
}