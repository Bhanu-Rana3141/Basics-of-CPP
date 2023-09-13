#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main() {

    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout<<"present or not ? : "<<binary_search(v.begin(),v.end(),6);

    int a = 3;
    int b =5;

    cout<<endl<<"max: "<<max(a,b)<<endl;
    cout<<"min: "<<min(a,b)<<endl;
    swap(a,b);
    cout<<"a: "<<a<<endl<<"b: "<<b<<endl;

    string str = "abcd";
    reverse(str.begin() , str.end());
    cout<<str;
}   