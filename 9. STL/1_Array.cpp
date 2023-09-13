#include<iostream>
#include<array>
using namespace std;

int main() {
    //declaration
    array<int,4> a = {1,2,3,4};

    //size
    int size = a.size();
    cout<<"size: "<<size<<endl;

    //Accessing arr elements
    for(int i=0; i<size; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    // accessing element from index
    cout<<"Element a index 2: "<<a.at(2)<<endl;

    //returns true/false in terms of 0/1
    cout<<"Empty array ? : "<<a.empty()<<endl;

    //first element
    cout<<"front ele : "<<a.front()<<endl;

    //last element
    cout<<"Back ele : "<<a.back();

}
