#include<iostream>
#include<algorithm>
using namespace std;

void removeSpaces(string& s, int pos) {
    while(s[pos] == ' ') {
        s.erase(pos, 1);
    }
}

void reversee(string& s, int i, int j) {
    j=j-1;
    while(i<j) {
        swap(s[i], s[j]);
        i++,j--;
    }
}

int main() {

    string s;
    cout << "Enter string: ";
    getline(cin, s);

    removeSpaces(s, 0);
       
    reverse(s.begin(), s.end());

    removeSpaces(s, 0);

    int i=0, j=0;
    int size = s.size();

    while(j < size) {
        if(s[i] == ' ') {
            s.erase(i, 1);
            i++;
            j=i;
        }
        else if(s[j] == ' ') {
            reversee(s,i,j);
            j++, i=j;
            removeSpaces(s, i);
        }
        else if(s[j] == s.size()-1) {
            reversee(s,i,j);
        }
        else{
            j++;
        }
    }

    cout << s;
    
    return 0;
}