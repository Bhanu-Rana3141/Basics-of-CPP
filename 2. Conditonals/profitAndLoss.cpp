#include<iostream>
using namespace std;

int main() {

    int cp;
    cout<<"Enter cost price: ";
    cin>>cp;

    int sp;
    cout<<"Enter selling price: ";
    cin>>sp;

    if(cp>sp)
        cout<<"LOSS";
    else if(sp>cp)
        cout<<"PROFIT";
    else
        cout<<"NEITHER PROFIT NOR LOSS";
    


    return 0;
}