#include<iostream>
#include<vector>
using namespace std;

char toLowerCase(char ch) {
    if(ch >= 'a' && ch <= 'z') {
        return ch;
    }
    else{
        return ch-'A'+'a';
    }
}

pair<char, int> maxOccurence(string s) {

    vector<int> freq(26,0);

    for(int i=0; i<s.size(); i++) {
        freq[s[i] - 'a']++;
    }   

    int ans = 0;
    int idx = 0;
    for(int i=0; i<26; i++) {
        if(freq[i] > ans) {
            ans = freq[i];
            idx = i;
        }
    }
    char ch = idx + 'a';
    return {ch, ans};
}

int main() {

    string s;
    cout << "Enter string: " ;
    cin >> s;

    // converting in lower case
    for(int i=0; i<s.size(); i++) {
        s[i] = toLowerCase(s[i]);
    }

    pair<char, int> p = maxOccurence(s);
    cout << p.first << " : " << p.second;
    
    return 0;
}