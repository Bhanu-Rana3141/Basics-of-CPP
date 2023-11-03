#include<iostream>
using namespace std;

int score = 10; // global variable

int a(int& i){
    cout << "In a: " << score << endl;
    score++;
    cout << i << endl;
}

int b(int& i){
    cout << "In b: " << score << endl;
    cout << i << endl;
}

int main() {
    cout << "In main: " << score << endl;
    int i = 5;
    a(i);
    b(i);

    return 0;
}