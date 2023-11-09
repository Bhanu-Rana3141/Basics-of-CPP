#include<iostream>
using namespace std;

int main() {
    int length,breadth;
    cout<<"Enter length and breadth: ";
    cin>>length>>breadth;

    if(length==breadth){
        cout<<"It is a square";
    }else{
        cout<<"Not a square";
    }
    return 0;
}