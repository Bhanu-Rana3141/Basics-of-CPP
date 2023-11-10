#include<iostream>
using namespace std;

int main() {

    // The time complexity (TC) of this code is O(1). This is because the loop will always iterate a constant number of times, in this case, 11 times (from i=0 to i=10). The number of iterations is not dependent on the input size or any variable; it's a fixed number. Therefore, the time complexity is constant, and we express that as O(1).
    
    for(int i=0; i<=10; i++) {
        cout << i << " ";
    }

    return 0;
}