#include<iostream>
using namespace std;

int count(int num){
    int count = 0;
    while(num > 0){
        int x = num % 10;
        if(x==1){
            count++;
        }
        num /= 10;
    }
    return count;
}

int binary(int num){
    int binary = 0;
    int power = 1;
    while(num > 0){
        int x = num % 2;
        binary += power*x;
        power *= 10;
        num /= 2;
    }
    return binary;
}

int main() {

    int a;
    cout << "Enter a: ";
    cin >> a;

    int b;
    cout << "Enter b: ";
    cin >> b;

    int a_binary = binary(a);
    int b_binary = binary(b);

    cout << "a: " << a_binary << endl;
    cout << "b: " << b_binary << endl;

    int a_oneCount = count(a_binary);
    int b_oneCount = count(b_binary);

    cout << "a_oneCount: " << a_oneCount << endl;
    cout << "b_oneCount: " << b_oneCount << endl;

    cout << "Total count of 1: " << a_oneCount+b_oneCount;

/* Approach - Using bitwise &

#include<iostream>
using namespace std;

int count(int n) {

    int count = 0;
    while(n != 0) { 
        if(n&1) {
            count++;
        }
        n = n>>1;
    }
    return count;
}

int main() {

    int a;
    cout<<"Enter a: ";
    cin>>a;

    int b;
    cout<<"Enter b: ";
    cin>>b;

    int a_setbits = count(a);
    int b_setbits = count(b);

    cout << "a: " << a_setbits << endl;
    cout << "b: " << b_setbits << endl;

    int total = a_setbits + b_setbits;
    cout << "total: " << total;
*/
    return 0;   
}