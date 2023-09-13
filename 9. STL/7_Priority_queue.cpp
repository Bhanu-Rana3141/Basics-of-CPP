#include<iostream>
#include<queue>
using namespace std;

int main() {

    //MAX HEAP 
    priority_queue<int> max;

    //MIN HEAP
    priority_queue<int,vector<int> , greater<int> > min;

    max.push(1);
    max.push(3);
    max.push(2);
    max.push(0);

    int n = max.size();
    for(int i=0; i<n; i++){
        cout<<max.top()<<" ";
        max.pop();
    }cout<<endl;


    min.push(1);
    min.push(3);
    min.push(2);
    min.push(0);

    for(int i=0; i<n; i++){
        cout<<min.top()<<" ";
        min.pop();
    }cout<<endl;

    cout<<"Khali h kya bhai: "<<min.empty();
    return 0;
}