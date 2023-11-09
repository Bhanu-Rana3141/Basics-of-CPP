#include<iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

/* Approach 1 -> convert n into binary and count no of 1

    int temp = n;
    int binary = 0;
    int power = 1;

    while(n>0) {
        int x = n%2;
        binary = binary + (power*x);
        power *= 10;
        n /= 2;
    }

    cout << "Binary of " << temp << " : " << binary << endl;

    int count = 0;
    while(binary > 0) {
        int x = binary % 10;
        if(x == 1) {
            count++;
        }
        binary /= 10;
    }
    cout << "count : " << count;

*/


// Approach 2 -> use of bitwise & and right shift by 1 after every iteration
       int count = 0;
        while(n != 0) {

            if(n&1) {
                count++;
            } 
            n = n>>1;
        }
        cout << count;
    
    return 0;
}