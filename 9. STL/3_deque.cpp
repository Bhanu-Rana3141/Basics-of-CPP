#include<iostream>
#include<deque>
using namespace std;

int main(){

    // push_back()
    //push_front()

    //pop_back()
    //pop_front()

    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    d.push_back(10);
    d.push_front(20);

    for(int i : d){
        cout<<i<<" ";
    }cout<<endl;

    // d.pop_back();
    // d.pop_front();
    // for(int i : d){
    //     cout<<i<<" ";
    // }


    // front()
    // end()
    cout<<"front ele: "<<d.front()<<endl;
    cout<<"back ele: "<<d.back()<<endl;

    cout<<"Element at index 1: "<<d.at(1)<<endl;

    // for(int i : d){
    //     d.pop_back();
    // }


    //empty()
    cout<<"empty or not: "<<d.empty()<<endl<<endl;


    //erase(start,end)

    cout<<"Before erase: ";
    cout<<"size: "<<d.size()<<endl;

    cout<<"After erase: ";
    d.erase(d.begin(),d.end()-1);
    for(int i : d){
        cout<<i<<" ";
    }cout<<endl;
    cout<<"size: "<<d.size()<<endl;

    



    

    return 0;
}