#include<iostream>
using namespace std;

int main() {
    char ch[6] = "abcde";
    cout<<ch<<endl;

    // ch -> pointing to first element of array
    char *c = &ch[0];
    cout<<c<<endl;

    cout<<*c;
    return 0;
}