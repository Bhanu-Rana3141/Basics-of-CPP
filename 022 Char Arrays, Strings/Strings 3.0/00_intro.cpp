#include<iostream>
#include<string.h>
using namespace std;

int getLength(string s) {
    int i=0;
    int length = 0;

    while(s[i] != '\0') {
        length++;
    }
    return length;
}

string subString(string str, int startPos, int noOfCharacters) {
    string ans = "";
    for(int i=0; i<str.length(); i++) {
        if(i == startPos) {
           for(int j=i; j<noOfCharacters+i; j++) {
            ans.push_back(str[j]);
           }
           break;
        }  
    }
    return ans;
}

bool compare(string s1, string s2) {
    if(s1.length() != s2.length()) {
        return false;
    }
    for(int i=0; i<s1.length(); i++) {
        if(s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}

// int find(string str, string target) {
//     for(int i=0; i<str.length(); i++) {
//         cout << str.substr(i, target.length()) << endl;
//         if(str.substr(i, target.length()) == target) {
//             cout << endl << "Found here -> " << str.substr(i, target.length()) << endl;
//             return i;
//         }
//     }   
//     return -1;
// }

int find(string str, string target) {
    for(int i=0; i<str.length();) {
        bool isEqual = true;
        for(int j=0; j<target.length(); j++) {
            if(str[i] == ' ') {
                i++;
                break;
            }
            if(str[i] == target[j]) {
                i++;
            }
            else{
                isEqual = false;
                i++;
            }   
        }
        if(isEqual == true) {
            return i-target.length();
        }
    }
    return -1;
} 

void replace(string& s, char oldChar, char newChar) {
    for(int i=0; i<s.size(); i++) { 
        if(s[i] == oldChar) {
            s[i] = newChar;
        }
    }
}

string erase(string& str, int& pos, int& noOfCharacters) {
    string ans = "";
    for(int i=0; i<str.length(); i++) {
        cout << i << " ";
        if(i == pos) {
            i += noOfCharacters;
        }
        ans.push_back(str[i]);
    }
    return ans;
}

int main() {

/*   char ch[100];
    cin >> ch;
   
    for(int i=0; i<9; i++) {
        cout << "index: " << i << " value: " << ch[i] << endl;
    }

    char name[100];
    cin.getline(name, 50); 
    // getline(cin, name); -> used in strings
    cout << name;
*/
 
    // SUBSTRING
    // string str;
    // getline(cin, str);
    // cout << str.substr(1, 4) << endl; // 1 represents starting index and 4 represents no of chracters of substring
    // int startPos;
    // cout << "Enter starting pos: ";
    // cin >> startPos;
    // int noOfCharacters;
    // cout << "Enter no of characters want in substring: ";
    // cin >> noOfCharacters;
    // string ans = subString(str, startPos, noOfCharacters);
    // cout << ans;

    // COMPARE 
    // s1.compare(s2) == 0 -> both strings are equal 
    // s1.compare(s2) != 0 , CASE 1 : > 0 if first character of s1 is greater than s2,   CASE 2: < 0 smaller 
    // string s1;
    // cout << "Enter s1: ";
    // cin >> s1;
    // string s2;
    // cout << "Enter s2: ";
    // cin >> s2;
    // if(s1.compare(s2) == 0) {
    //     cout << "Both are exactly same";
    // }
    // else{
    //     cout << "Not same";
    // }
    // if(compare(s1,s2) == 1) {
    //     cout << "Both are equal";
    // }
    // else{
    //     cout << "Not equal";
    // }
    // string x = "bbbb";
    // string y = "bbbba";
    // cout << x.compare(y) << endl;

    // FIND -> uses linear search algorithm 
    // string sentence = "hello jee kya haal chaal";
    // string target = "haal";
    // cout << sentence.find(target);
    //npos -> if we are finding a part of string in main string, if it is present then index will be returned else no position will be returned
    // if(sentence.find(target) == string::npos) {
    //     cout << string::npos; // not found
    // }
    // int index = find(sentence, target);
    // cout << "found at : " << index;
    
    // REPLACE -> s.replace(starting index, no of characters to be replaced, new characters or substring)
    // string sentence = "my name is Bhanu";
    // cout << sentence << endl;
    // sentence.replace(11, 5, "Partap");
    // cout << sentence << endl;
    // string s2 = "Singh";
    // sentence.replace(11,6, s2);
    // cout << sentence << endl;
    // sentence.replace(11,7, "Rana");
    // cout << sentence << endl;
    // string s = "hello jee kya haal chaal";
    // cout << s << endl;
    // char newChar = 'z';
    // replace(s, 'a', newChar);
    // cout << s << endl;

    // ERASE -> s.erase(start pos, no of characters to be deleted )
    // string s = "abcdefghijkl"; 
    // s.erase(0, 4);
    // cout << s << endl;
    // s.erase(s.begin(), s.begin()+4);
    // cout << s << endl;
    
    // erase custom implementation
    // string str;
    // cout << "Enter string: ";
    // getline(cin, str);
    // int startPosition;
    // cout << "starting pos for erase: ";
    // cin >> startPosition;
    // int noOfCharacters;
    // cout << "no of characters to erase: ";
    // cin >> noOfCharacters;
    // string ans = erase(str, startPosition, noOfCharacters);
    // cout << ans;

    return 0;
}
