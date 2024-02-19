#include<iostream>
#include<algorithm>
using namespace std;

int binarySearch(string &s, int start, int end, char target) {

    int mid = start+(end-start)/2;

    while(start <= end) {
        if(s[mid] == target) {
            return mid;
        }
        else if(s[mid] > target) {
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start+(end-start)/2;
    }
    return -1;
}

int main() {

    string s;
    cout << "Enter s: ";
    getline(cin, s);

    char target;
    cout << "Enter target: ";
    cin >> target;

    int index = binarySearch(s, 0, s.size()-1, target);

    if(index > -1) {
        cout << "Element present at index: " << index;
    }
    else{
        cout << "Element not present";
    }
    
    return 0;
}