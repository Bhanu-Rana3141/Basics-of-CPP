#include<iostream>
using namespace std;

// pass by value
int power(int n){
    if(n == 0)
        return 1;
    
    return 2*power(n-1);
}

// pass by reference
void power(int n, int& ans) {
    if(n == 0) {
        return;
    }
    ans = 2*ans;
    power(n-1, ans);
}

int main() {
    
    int n;
    cout << "Enter n: ";
    cin >> n;

    // cout << power(n);

    int ans = 1;
    power(n,ans);
    cout << "ans : " << ans;
    return 0;   
}