#include<iostream>
using namespace std;

bool voteEligibility(int age){
    if(age>=18){
        return true;
    }else{
        return false;
    }
}

int main() {
    int age;
    cout<<"Enter age: ";
    cin>>age;

    if(voteEligibility(age) == true){
        cout<<"CAN VOTE";
    }else{
        cout<<"CANNOT VOTE";
    }
    return 0;
}