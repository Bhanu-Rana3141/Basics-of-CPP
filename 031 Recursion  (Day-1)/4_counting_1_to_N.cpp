#include<iostream>
using namespace std;

// Counting N to 1   -> Head Recursion

void print_counting(int n){

//Base Case
    if(n==0){  
        return;
    }

// Recursive Relation 
   print_counting(n-1);

// Processing
   cout<<n<<" ";

}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    print_counting(n);
    return 0;
}