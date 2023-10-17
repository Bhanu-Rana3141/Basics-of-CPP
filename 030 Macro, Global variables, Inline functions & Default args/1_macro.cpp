#include<iostream>
using namespace std;

// creating macro -> no memory allocation
#define PI 3.14

int main() {    
    
    int r = 5;
    // double pi = 3.14;  By using double a memory of 8 byte is allocated which hits performance
    double area = PI * r* r;
    cout<<PI<<endl;
    cout<<area;

    return 0;
}