#include<iostream>
using namespace std;

inline int getMax(int& a, int& b){
    return a>b? a:b;
}

int main() {
    cout << endl;

    int a = 1,b = 2;
    int ans = getMax(a,b);

    cout << "max: " << ans;

    return 0;
}