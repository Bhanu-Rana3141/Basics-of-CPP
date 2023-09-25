#include<iostream>
#include<vector>
using namespace std;

char toLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}


bool isPalindrome(vector<char>&s){
    int start=0;
    int end=s.size()-1;

    while(start<end){
        if(toLowerCase(s[start]) != toLowerCase(s[end])){
            return 0;
        }
        else{
            start++;
            end--;
            }
    }
    return 1;
}

int main() {
    cout<<"Enter size: ";
    int n;
    cin>>n;
    
    vector<char>s(n);
    for(int i=0; i<n; i++){
       cin>>s[i];
    }

    if(isPalindrome(s)){
        cout<<"String is palindrome";
    }
    else{
        cout<<"not palindrome";
    }
    return 0;
}