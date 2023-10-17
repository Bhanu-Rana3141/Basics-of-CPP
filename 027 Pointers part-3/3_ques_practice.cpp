#include<iostream>
using namespace std;

int main() {
    cout<<endl<<endl;

    int first = 8;
    int second = 18;
    int *ptr = &second;
    *ptr = 9;

    cout<<first<<" "<<second<<endl;

    cout<<endl<<endl;
    return 0;
}