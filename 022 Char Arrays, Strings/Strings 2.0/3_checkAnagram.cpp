/* TC -> O(n) && SC -> O(1) in all the cases
APPROACH 1
* sort both the strings using 
* compare them, if they are equal then anagram else not anagram

APPROACH 2 
* create freq vector for both string and store freq of each alphabet
* then use a loop to check whether frequency of alphabets in both the vectors are same, if same "anagram" else "not anagram"

OPTIMISED version of APPROACH 2
* As in previous approach we are creating 2 vectors for storing frequency, but we can do same just by using 1 vector
* here we will increment the frequency of alphabets in string 1 and decrement the frequency in string 2
* After doing this, if all the alphabets are same then 0 will be present at all indexes of freq vector
* If 0 is present then it is anagram, else not 

*/

#include<iostream>
#include<vector>
using namespace std;

string countSort(string s) {

    vector<int> freq(26,0);

    for(int i=0; i<s.size(); i++) {
        freq[s[i]-'a']++;
    }

    int j=0;
    for(int i=0; i<26; i++) {
        while(freq[i]--) {
            s[j] = i+'a';
            j++;
        }
    }
    return s;
}

void printFrequencyVector(vector<int> freq) {

    for(int i=0; i<freq.size(); i++) {
        cout << freq[i] << " ";
    }
    cout << endl;
}

bool isAnagram(string s, string t) {

    // for storing freq of alphabets in s and t
    vector<int> freqOfS(26,0);
    vector<int> freqOfT(26,0);

    for(int i=0; i<s.length(); i++) {
        freqOfS[s[i]-'a']++;
    }

    for(int i=0; i<t.length(); i++) {
        freqOfT[t[i]-'a']++;
    }

    cout << "Frequency vector of s: ";
    printFrequencyVector(freqOfS);

    cout << "Frequency vector of t: ";
    printFrequencyVector(freqOfT);

    for(int i=0; i<26; i++) {
        if(freqOfS[i] != freqOfT[i]) {
            return false;
        }
    }
    return true;
}

bool isAnagramOptimised(string s, string t) {

    vector<int> freq(26,0);

    for(int i=0; i<s.length(); i++) {
        freq[s[i]-'a']++;
        freq[t[i]-'a']--;
    }

    for(int i=0; i<26; i++) {
        if(freq[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {

    string s;
    cout << "Enter s: ";
    cin >> s;

    string t;
    cout << "Enter t: ";
    cin >> t;

/*  Approach 1 
    if(s.size() != t.size()) {
        cout << "No";
    }
    else{
        if(countSort(s) == countSort(t)) {
        cout << "yes";
        }
        else{
            cout << "no";
        }
    }
*/

/*  Approach 2 
    if(s.length() != t.length()) {
        cout << "Not anagram";
    }
    else{
        if(isAnagram(s,t)) {
        cout << "strings are anagram";
        }
        else{
            cout << "Not anagram";
        }
    }
*/

//  Approach 3   
    if(s.size() != t.size()) {
        cout << "No";
    }
    else{
        if(isAnagramOptimised(s,t)) {
        cout << "strings are anagram";
        }
        else{
            cout << "Not anagram";
        }
    }
    
    return 0;
}