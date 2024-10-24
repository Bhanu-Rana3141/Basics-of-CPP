#include<iostream>
using namespace std;

char toLowercase(char ch) {

    return ch-'A'+'a';
}

bool isPalindrome(string s, int i, int j) {

    while(i < j) {

        if(s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = toLowercase(s[i]);
        }

        if(s[j] >= 'A' && s[j] <= 'Z') {
            s[j] = toLowercase(s[j]);
        }

        if(s[i] != s[j]) {
            return false;
        }
        else {
            i++;
            j--;
        }
    }
    return true;
}

int countPalindromes(string& s) {

    int i = 0;
    int j = 0;
    int cnt = 0;
    int n = s.size();
    string temp = s;

    while(j < n) {
        if((s[j] == ' ') || (j == n-1)) {
            if(j == n-1) {
                if(isPalindrome(temp, i, j)) cnt++;
                break;
            }
            else {
                if(isPalindrome(temp, i, j-1)) cnt++;
            }
            i = j+1;
            j = i;
            continue;
        }
        j++;
    }
    return cnt;
}

int main()
{
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    int noOfPalindromes = countPalindromes(s);
    cout << "No Of Palindromes: " << noOfPalindromes;

    return 0;
}