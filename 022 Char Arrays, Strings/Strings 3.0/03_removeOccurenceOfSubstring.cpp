/*
Q. What is nopos ? and why we can't find substring with this comparison s.find(sub) with null character ?
-> The null character '\0' is used in C and C++ to represent the end of a string. It is not a valid index to check when using the find function. The find function returns the position (index) of the first occurrence of the substring within the main string or string::npos if the substring is not found.std::string::npos is a constant representing the maximum possible value for the size_t type, which is the type used for string indices in C++. It does not represent a valid index within the string. When the find function fails to find the substring, it returns std::string::npos to indicate that the substring is not present.


TC -> 
* find function has a time complexity of O(N*M), where N is the size of the string s and M is the   size of the string part.
* The erase function has a time complexity of O(N), where N is the size of the string s.
* so the overall time complexity of the function can be expressed as O(K * N * M), where K is the number of occurrences of the substring part in the string s.

SC -> O(1)
*/

#include<iostream>
using namespace std;

void removeOccurence(string& s, string part) {
    
    while(s.find(part) != string::npos) {
        s.erase(s.find(part), part.length());
    }
}

int main() {

    string s;
    cout << "Enter string: ";
    cin >> s;

    string part = "abc";
    removeOccurence(s, part);

    cout << s;
    
    return 0;
}