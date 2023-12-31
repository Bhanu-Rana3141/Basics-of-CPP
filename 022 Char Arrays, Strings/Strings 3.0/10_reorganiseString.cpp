/*
* Create a hash count
* find maximum occuring character
* place maximum occuring char on alternate positions, if its gets placed true else false
TC : O(n)
*/

#include<iostream>
#include<limits.h>
using namespace std;

int main() {

    string s;
    cout << "Enter string: ";
    cin >> s;

    // frequeny count - O(n) : n size of string
    int freq[26] = {0};
    for(int i=0; i<s.size(); i++) {
        freq[s[i] - 'a']++;
    } 

    // max occuring character and it's frequency
    int maxFreq = INT_MIN;
    char maxFreqChar;
    for(int i=0; i<26; i++) {
        if( freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxFreqChar = i+'a';
        }
    }

    // placing max occuring char on alternate positions - O(n/2) : O(n)
    int index = 0;
    while(maxFreq > 0 && index < s.size()) {
        s[index] = maxFreqChar;
        maxFreq--;
        index += 2;
    }

    // checking whether the max freq char got completely placed
    if(maxFreq != 0) {
        cout << "Can't reorganise";
        return 0;
    }

    freq[maxFreqChar - 'a'] = 0;

    for(int i=0; i<26; i++) {
        while(freq[i] > 0) {
            if(index >= s.size()) {
                index = 1;
            }
            s[index] = i + 'a';
            index += 2;
            freq[i]--;
        }
    }

    cout << "organised string : " << s;
    
    return 0;
}