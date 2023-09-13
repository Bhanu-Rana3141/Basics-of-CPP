#include<iostream>
#include<map>
using namespace std;

int main() {
    map<int,string> m;

    m[1] = "babbar";
    m[13] = "kumar";
    m[2] = "love";

    m.insert({5,"bheem"});

    cout<<"before erase: "<<endl;
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<endl<<"Finding ele : "<<m.count(13)<<endl<<endl;
    m.erase(13);

    cout<<"After erase: "<<endl;
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    } 
    return 0;
}
