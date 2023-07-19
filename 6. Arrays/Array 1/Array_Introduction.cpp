#include<iostream>
using namespace std;

int main() {
    char vowels[5];

    for(char ele : vowels){
        cin>>ele;
    }

    for(char ele : vowels){
        cout<<ele<<" ";
    }

    
    return 0;
}