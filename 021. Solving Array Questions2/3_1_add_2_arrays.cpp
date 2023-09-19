#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr_to_integer(vector<int>arr, int n){
    int i=0;
    int integer_val = 0;
    while(i<n){
        int x = arr[i] % 10;
        integer_val = integer_val * 10 + x;
        i++;
    }
    return integer_val;
}

void sum_array(int sum,vector<int>&res, int size){
    
    while(sum>0){
        int x = sum%10;
        res.push_back(x);
        sum/=10;
    }
    reverse(res.begin(), res.end());

    for(int i=0; i<size; i++){
        cout<<res[i]<<" ";
    }
}
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

    int size = 0;
    (n>m) ? size=n : size = m;

    vector<int>b(m);
    for(int i=0; i<m; i++){
        cin>>b[i];
    }

    // Converting array as integer
    int a_integer = arr_to_integer(a,n);
    int b_integer = arr_to_integer(b,m);

    cout<<"a: "<<a_integer<<endl;
    cout<<"b: "<<b_integer<<endl;
    
    int sum = a_integer + b_integer;
    cout<<"Sum as integer : "<<sum<<endl;

    // Now converting integer back to array
    vector<int>res;
    cout<<"Resultant array: ";
    sum_array(sum,res,size);
    return 0;
}