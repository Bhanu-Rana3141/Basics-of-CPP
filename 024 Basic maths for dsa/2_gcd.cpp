#include<iostream>
using namespace std;

//Euclid's algorithm : gcd(a,b) = gcd(a-b,b) , gcd(a%b,b)
// TC -> O(max(a,b))

// gcd -> smaller b|w the given 2 number
// lcm -> larger b|w  the given 2 numbers

int gcd(int a, int b){
    if(a==0) {
        return b;
    }
    if(b==0){
        return a;
    }

    while(a != b){
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
    }
    return a;
}

int main() {
    int a;
    cout<<"Enter a: ";
    cin>>a;

    int b;
    cout<<"Enter b: ";
    cin>>b;

    int ans = gcd(a,b);
    cout<<"gcd: "<<ans;
    cout<<endl;

    int lcm = (a*b)/ans;
    cout<<"lcm: "<<lcm;
    return 0;
}