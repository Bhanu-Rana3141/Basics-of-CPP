#include<iostream>
#include<string.h>
using namespace std;

int getLength(char sentence[]) {
    int length = 0;

    int i=0;
    while(sentence[i] != '\0') {
        length++;
        i++;
    }
    return length;
}

void replaceSpaces(char sentence[], int length) {
    for(int i=0; i<length; i++) {
        if(sentence[i] == ' ') {
            sentence[i] = '@';
        }
    }
    return;
}

int main() {

    char sentence[100];
    cout << "Enter sentence: ";
    cin.getline(sentence, 100);

    int length = getLength(sentence);

    replaceSpaces(sentence, length);
    cout << sentence;
    
    return 0;
}