#include<iostream>
#include<vector>
using namespace std;


int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    vector<int>v(n);
    for(int i=0; i<v.size(); i++){
        cin>>v[i];
    }

    int even_sum=0;
    int odd_sum=0;

    for(int i=0; i<v.size(); i++){
        if(i%2==0){
            even_sum+=v[i];
        }else{
            odd_sum+=v[i];
        }
    }

    int diff = odd_sum-even_sum;
    cout<<"diff : "<<diff;
    
    
    return 0;   
}