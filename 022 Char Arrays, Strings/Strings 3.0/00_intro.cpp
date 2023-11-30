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

int main() {

/*  
    char ch[100];
    cin >> ch;
   
    for(int i=0; i<9; i++) {
        cout << "index: " << i << " value: " << ch[i] << endl;
    }

    char name[100];
    cin.getline(name, 50); 
    // getline(cin, name); -> used in strings
    cout << name;
*/
 
    // string str;
    // cin >> str;

    // SUBSTRING
    // cout << str.substr(1,3) << endl; // 1,3 are inclusive



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



    // FIND
    // string sentence = "hello jee kya haal chaal";
    // string target = "z";
    // cout << sentence.find(target);

    //npos -> if we are finding a part of string in main string, if it is present then index will be returned else no position will be returned
    // if(sentence.find(target) == string::npos) {
    //     cout << string::npos; // not found
    // }
    


    // REPLACE -> s.replace(starting pos, no of characters to be replaced, last pos)
    // string sentence = "my name is Bhanu";
    // cout << sentence << endl;
    // sentence.replace(11, 5, "Partap");
    // cout << sentence << endl;

    // string s2 = "Singh";
    // sentence.replace(11,6, s2);
    // cout << sentence << endl;

    // sentence.replace(11,7, "Rana");
    // cout << sentence << endl;
    

    // ERASE -> s.erase(start pos, no of characters to be deleted )
    // string s = "abcdefghijkl"; 
    // s.erase(0, 4);
    // cout << s << endl;
    // s.erase(s.begin(), s.begin()+4);
    // cout << s << endl;

    // isalpha
    // islower
    return 0;
}