#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int sum=0;
    for(int i=1; i<=n; i++){
        sum+=i;
    }
    int decimal=sum;
    int binary=0,power=1;
    while(decimal>0){
        int x = decimal%2;
        binary += x*power;
        power*=10;
        decimal/=2;
    }

    cout<<"Decimal Sum: "<<sum<<endl<<"Binary Sum: "<<binary;
    return 0;
}