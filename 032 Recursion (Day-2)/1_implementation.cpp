#include<iostream>
using namespace std;

void reachHome(int src, int dest){
    cout << "Step: " << src << "  Destination: " << dest << endl;
    // Base Case
    if(src == dest) {
        cout << "Finally reached Home";
        return;
    }
    // Processing
    src++;
    // Recursive call
    reachHome(src, dest);
}

int main() {

    int src=1;
    int dest=10;

    reachHome(src, dest);

    return 0;
}