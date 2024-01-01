/*
APPROACH 1 : using find function
Time Complexity: O(N + M)
Space Complexity: O(1)
The find function in C++ typically uses efficient string searching algorithms such as Knuth-Morris-Pratt (KMP) or Boyer-Moore. The time complexity of find is generally O(N + M), where N is the length of the haystack and M is the length of the needle

APPROACH 2 : sliding window using substr function
The outer loop runs haystack.length() times, where haystack.length() is the length of the haystack string.
For each iteration of the loop, the substr function is called, which takes O(needle.length()) time. The comparison haystack.substr(i, needle.length()) == needle also takes O(needle.length()) time in the worst case.
Therefore, the overall time complexity is O(N * M), where N is the length of the haystack and M is the length of the needle.
Time Complexity: O(N * M)
Space Complexity: O(1)
*/

#include<iostream>
#include<string.h>
using namespace std;

// int firstOccurenceIndex(string haystack, string needle) {
//     return haystack.find(needle);
// }

int firstOccurenceIndex(string haystack, string needle) {
    for(int i=0; i<haystack.size(); i++) {
        if(haystack.substr(i, needle.length()) == needle) {
            return i;
        }
    }
    return -1;
}

int main() {

    string haystack;
    cout << "Enter string: ";
    cin >> haystack;
    
    string needle;
    cout << "Enter needle : ";
    cin >> needle;

    int firstOccurence = firstOccurenceIndex(haystack, needle);
    cout << "present at: " << firstOccurence;
   
    return 0;
}