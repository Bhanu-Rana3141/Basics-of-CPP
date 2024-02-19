#include<iostream>
#include<algorithm>
using namespace std;

void removeSpaces(string& s) {
    while(s.back() == ' ') {
        s.pop_back();
    }
}

void reversee(string& s, int i, int j) {
    while(i < j) {
        swap(s[i], s[j]);
        i++, j--;
    }
}

int main() {

    string s;
    cout << "Enter s: ";
    getline(cin, s);

    removeSpaces(s);
    reverse(s.begin(), s.end());
    removeSpaces(s);

    int i=0, j=0;
    while(j < s.size()) {
        if(s[j] == ' ') {
            reversee(s, i, j-1);
            j++;
            while(s[j] == ' ') {
                s.erase(j, 1);
            }
            i=j;
        }
        else if(s[j+1] == '\0') {
            reversee(s, i, j);
            break;
        }
        else {
            j++;
        }
    }

    cout << s;
    
    return 0;
}