#include <iostream>
using namespace std;

bool checkValid(string s) { 

    int n = s.size();
    int cnt = 0;

    for(int i = 0; i<s.size(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            return false;
        }
        else if(s[i] == '.' || s[i] == '!' || s[i] == ',') {
            if(i < n-1) return false;
        }
        else if(s[i] == '-') {
            cnt++;
            if(cnt > 1) return false;
            if(i-1 >= 0 && (s[i-1] >= 'a' && s[i-1] <= 'z') && i+1 < n && (s[i+1] >= 'a' && s[i+1] <= 'z') ) {
                continue;
            }
            else {
                return false;
            }
        }
    }
    cout << "valid string: " << s << endl;
    return true;
}

int countValidWords(string s) {
        
    int cnt = 0;
    int i = 0;
    int j = 0;
    int n = s.size();
    
    while(j < n) {

        string word = "";
        if(s[j] == ' ' || j == n-1) {
            if(s[j] == ' ') {
                word += s.substr(i, j-i);
            }
            else {
                word += s.substr(i);
            }

            cout << "word: " << word << endl;
            if(checkValid(word)) cnt++;
            j++;
            while(s[j] == ' ') {
                j++;
            }
            i = j;
            continue;
        }
        j++;
    } 

    return cnt;
}

int main() {

    string sentence = "sx  1,  x";
    
    cout << "cnt: " << countValidWords(sentence);

    return 0;
}