// Calculate Substring : n*(n+1)/2;
/*
APPROACH 1: 
1. find all substrings , using 2 loops    TC : O(n^2)
2. checking palindrome : O(n)
Overall : O(n^3)

APPROACH 2: 
1. two loops are used 1 to iterate through each character and find count of even and odd palindrome by using 2 pointers expanding from center to left and right
TC:O(n^2)
SC:O(1)

*/

#include<iostream>
#include<vector>
using namespace std;

/*bool isPalindrome(string s) {

    int i = 0;
    int j = s.size()-1;
    while(i <= j) {
        if(s[i] != s[j]) {
            return false;
        }
        else{
            i++, j--;
        }
    }
    return true;
}

int main() {

    string s;
    cout << "Enter s: ";
    cin >> s;

    int n = s.size();
    
    vector<string>substrings;

    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            substrings.push_back(s.substr(i, j-i+1));
        }
    }

    for(int i=0; i<substrings.size(); i++) {
        cout << substrings[i] << endl;
    }

    int count = 0;
    for(int i=0; i<substrings.size(); i++) {
       if(isPalindrome(substrings[i])) {
        count++;
       }
    }   

    cout << "Count: " << count; 

    return 0;
}
*/

int expandAroundCenter(string s, int left, int right) {
    int count = 0;
    while(left>=0 && right<s.size() && s[left] == s[right]) {
        count++;
        left--;
        right++;
    }
    return count;
}

int main() {

    string s;
    cout << "Enter s: " ;
    cin >> s;

    int count = 0;

    for(int center=0; center<s.size(); center++) {

        int oddCount = expandAroundCenter(s, center, center);
        count += oddCount;

        int evenCount = expandAroundCenter(s, center, center+1);
        count += evenCount;
    }

    cout << "total palindromic substrings: " << count;

    return 0;
}