#include<iostream>
using namespace std;

void update(int** p2){
    // p2 = p2+1;  // No change

    // *p2 = *p2+1;   // Yes

    **p2 = **p2+1; // Yes

}

int main() {
    int i=5;
    int* p = &i;
    int** p2 = &p;

    cout<<endl<<endl;

    cout<<"Before :"<<endl;
    cout<<"i: "<<i<<endl;
    cout<<"p: "<<p<<endl;
    cout<<"p2: "<<p2<<endl;

    cout<<endl;

    update(p2);

    cout<<"After :"<<endl;
    cout<<"i: "<<i<<endl;
    cout<<"p: "<<p<<endl;
    cout<<"p2: "<<p2<<endl;

    cout<<endl<<endl;
    return 0;
}