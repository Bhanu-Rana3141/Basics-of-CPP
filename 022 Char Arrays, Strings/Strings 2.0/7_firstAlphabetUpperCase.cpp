#include<iostream>
using namespace std;

 char isUpper(char ch) {
	
	if(ch >='a' && ch <= 'z') {
		return ch-'a'+'A';
	}
	else{
		return ch;
	}
}

int main() {

	string s;
    cout << "Enter s: ";
    getline(cin , s);

   	s[0] = isUpper(s[0]);

	for(int i=1; i<s.size(); i++) {
		if(s[i] == ' ') {
			i=i+1;
			s[i] = isUpper(s[i]);
		}
	}
    
    cout << s;

    return 0;
}