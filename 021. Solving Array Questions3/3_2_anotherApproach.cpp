#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cout<<"Enter size of array 1: ";
    cin>>n;

    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int m;
    cout<<"Enter size of array 2: ";
    cin>>m;

    vector<int>b(m);
    for(int i=0; i<m; i++){
        cin>>b[i];
    }

    int size = (n>m)? size=n : size=m;

    // Adding last elements of integer
    int i=n-1;
    int j=m-1;
    vector<int>ans;   // Vector to store sum
    int carry=0;

    while(i>=0 && j>=0){
        int val1 = a[i];
        int val2 = b[j];
        int sum = val1 + val2 + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--,j--;
    }

    // FIRST CASE : If array 1 has more elements than array 2
    while(i>=0){
        int sum = a[i]+carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }

    // SECOND CASE : If array 2 has more elements than array 1
    while(j>=0){
        int sum = b[j]+carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        j--;
    }


    // if carry is left
    while(carry != 0){
        int sum = carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    }

    reverse(ans.begin(),ans.end());
    for(int i=0; i<size; i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}