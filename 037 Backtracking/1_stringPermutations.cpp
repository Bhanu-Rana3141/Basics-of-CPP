/*WHAT IS BACKTRACKING ?

*Choose: Make a choice at the current decision point.
*Explore: Move to the next decision point and repeat step 1.
*Backtrack: If the choices made lead to an invalid solution, undo the last choice and go back to the previous decision point.
*Terminate: Stop when a valid solution is found or when all possibilities have been explored.

* can be solved without backtracking if string is passed by value
* But if string is passed by reference in that case backtracking should be used

BACKTRACKING TC : O(n!) - because there are (n!) permutations of string and it generates all possible permutations
*/

#include<iostream>
using namespace std;

void printPermutations(string s, int i) {
    if(i >= s.length()) {
        cout << s << " ";
        return;
    }

    for(int j=i; j<s.length(); j++) {
        swap(s[i], s[j]);
        printPermutations(s, i+1);
        swap(s[i], s[j]);
    }
}

int main() {

    string s;
    cout << "Enter string: ";
    cin >> s;
    int i=0;

    printPermutations(s,i);
    
    return 0;
}