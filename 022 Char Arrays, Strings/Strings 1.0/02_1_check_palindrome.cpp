#include<iostream>
#include<vector>
#include<algorithm>
#include <string.h>
using namespace std;

/* Approach -1 -> Reverse current string and store in another string, and then compare original string 
    with reversed string, if both are equal then it's palindrome else not palindrome .
    But in this approach we are creating another string to store reversed array so it will take extra space complexity.
*/

/* Approach 2 -> Using 2 pointer approach 
    -initialising 2 pointers 1 points to 0th index and other points to last index.
    -comparing value at pointer 1 with value at pointer 2, if they are not equal then it's not palindrome
    therefore if they are equal increment starting pointer with 1 and decrement ending pointer by 1
    -If loops gets completely exectued and it haven't return false, it means string is palindrome
*/

void print(char str[]) {
    for(int i=0; i<strlen(str); i++) {
        cout << str[i] << " ";
    }
}

bool isPalindrome_approach_1(char str[]) {

    int size = strlen(str);

    char rev[10];
    for(int i=0; i<size; i++) {
        rev[i] = str[size-i-1];
    }

    cout << "Printing original char array: ";
    print(str);
    
    cout << endl << endl;

    cout << "printing reversed char array: ";
    print(rev);

    cout << endl << endl;

    for(int i=0; i<size; i++) {
        if(str[i] != rev[i]) {
            return false;
        }
    }
    return true;
}

bool isPalindrome_approach_2(char str[]){

    int s = 0;
    int e = strlen(str)-1;

    while(s<e) {
        if(str[s] != str[e]) {
            return false;
        }
        else {
            s++, e--;
        }
    }
    return true;
}

int main() {
   
    cout << "Enter string: ";
    char str[10];
    cin >> str;

    int ans = isPalindrome_approach_1(str);

    // int ans = isPalindrome_approach_2(str, len);

    if(ans) {
        cout << "Palindrome"; 
    }
    else {
        cout << "Not Palindrome";
    }

    return 0;
}