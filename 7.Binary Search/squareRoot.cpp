#include<iostream>
using namespace std;

int binarySearch(int n){
    int s=0;
    int e=n;
    long long int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        long long int square = mid*mid;
        if(square*square == n){
            return mid;
        }
        else if(square*square> n){
            e=mid-1;
        }
        else{
            ans=mid;
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
}

double fraction(int n,int precision,int solution_Without_Sqrt){
    double ans=solution_Without_Sqrt;
    double factor =1;
    for(double i=0; i<precision; i++){
         factor = factor/10;
        for(double j=ans; j*j<n; j+=factor){
            ans=j;
        }
    }
    return ans;
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    
    int squareRoot = binarySearch(n);
    cout<<"Ans without sqrt: "<<squareRoot<<endl;
    cout<<"Ans with sqrt: "<<fraction(n,3,squareRoot);

    return 0;
}