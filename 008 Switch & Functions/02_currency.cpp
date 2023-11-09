#include<iostream>
using namespace std;

int main() {
    
    int amount = 1330;

    cout << "Amount : " << amount << endl;

    int hundredNotes = amount/100;
    int remainAmount = amount % 100;

    int fiftyNotes = remainAmount/50;
    remainAmount = amount % 50;

    int twentyNotes = remainAmount/20;
    remainAmount = amount % 20;

    int oneNotes = remainAmount/1;
    remainAmount = amount % 1;

    cout << "Hundred notes: " << hundredNotes << endl;
    cout << "Fifyt notes: " << fiftyNotes << endl;
    cout << "Twenty notes: " << twentyNotes << endl;
    cout << "One notes: " << oneNotes << endl;

    return 0;
}