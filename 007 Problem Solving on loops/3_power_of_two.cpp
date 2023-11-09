#include<iostream>
using namespace std;

/* Recursive logic

int power(int n) {
    if(n == 0) {
        return false;
    }
    if(n == 1) {
        return true;
    }

    if(n%2 != 0) {
        return false;
    }

    return power(n/2);
}
*/

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

/*Approch 1 - using loop
    
    for(int i=2; i<=n; i*=2) {
        cout << i << " ";
        if(i == n) {
            cout << endl << n << " : " << "true";
            return 0;
        }
    }

    cout << endl << n << " : "<< "false";
*/
    
/* Approach 2 - Recursion 
    if(power(n)) {
        cout << "true";
    }
    else{
        cout << "false";
    }
*/

// Approach 3 -> using bitwise operator

    if(n>0 & ((n & (n-1)) == 0)) {
        cout << "true";
    }
    else{
        cout << "false";
    }

    return 0;
}