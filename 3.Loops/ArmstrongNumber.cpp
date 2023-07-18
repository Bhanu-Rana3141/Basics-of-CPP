#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
   
    for(int i=1; i<=n; i++){
        int sum=0;
        int temp=i;
        while(temp>0){
            int x = temp%10;
            sum+=x*x*x;
            temp/=10;
        }

        sum==i ? cout<<i<<endl : cout<<"";
    }
    return 0;
}