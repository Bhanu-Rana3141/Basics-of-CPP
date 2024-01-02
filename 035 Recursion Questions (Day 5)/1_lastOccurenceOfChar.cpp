#include<iostream>
using namespace std;
// strrchr()

// iterating from right
int lastOccurence(string s, char ch, int index) {
    if(index < 0) {
        return -1;
    } 
    if(s[index] == ch) {
        return index;
    }
    return lastOccurence(s, ch, index-1);
}

// iterating from left
void lastOccurence(string s, char ch, int index, int& ans) {
    if(index >= s.size()) {
        return;
    } 
    if(s[index] == ch) {
        ans = index;
    }
    lastOccurence(s, ch, index+1, ans);
}

int main() {

    string s;
    cout << "Enter string: ";
    cin >> s;

    char ch;
    cout << "Enter ch: ";
    cin >> ch;

    int index = lastOccurence(s, ch, s.size()-1);
    cout << "Last occurence of " << ch << " is : " << index; 

    // int ans = -1;
    // lastOccurence(s, ch, 0, ans);
    // cout << ans;
    
    return 0;
}