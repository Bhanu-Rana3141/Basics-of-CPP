#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> mpp;

    pair<string, int> p = make_pair("love", 1);
    mpp.insert(p);

    pair<string, int> p2("babbar", 2);
    mpp.insert(p2);

    mpp["mera"] = 3;
    

    // cout << mpp["unknownkey"] << endl;
    // cout << mpp.at("unknownkey") << endl;

    cout << mpp.size() << endl;

    // to check if element present  - count()
    cout << mpp.count("love") << endl;

    // erase()
    mpp.erase("love");
    cout << mpp.size() << endl;


    // method 1 - printing mpp
    for(auto it : mpp) {
        cout << it.first << " -> " << it.second << " , ";
    }

    cout << endl;
    
    // method 2
    unordered_map<string, int> :: iterator it = mpp.begin();

    while(it != mpp.end()) {
        cout << it->first << " " << it->second << " , ";
        it++;
    }

    return 0;
}