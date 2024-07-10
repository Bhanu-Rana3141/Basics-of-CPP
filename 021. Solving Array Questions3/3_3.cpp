#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> sum(vector<int> arr1, int n, vector<int> arr2, int m) {

    vector<int> ans;
    int i = n-1;
    int j = m-1;
    int carry = 0;

    while(i >= 0 || j >= 0 || carry != 0) {
        int n1 = 0;
        if(i >= 0) {
            n1 = arr1[i];
        }

        int n2 = 0;
        if(j >= 0) {
            n2 = arr2[j];
        }

        int sum = n1 + n2 + carry;
        int digit = sum % 10;
        carry = sum/10;

        ans.push_back(digit);
        i--, j--;
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

int main()
{
    
    int n;
    cin >> n;
    vector<int> arr1;
    for(int i = 0; i<n; i++) {
        int ele;
        cin >> ele;
        arr1.push_back(ele);
    }

    int m;
    cin >> m;
    vector<int> arr2;
    for(int i = 0; i<m; i++) {
        int ele;
        cin >> ele;
        arr2.push_back(ele);
    }

    vector<int> ans = sum(arr1, n, arr2, m);

    for(int i = 0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}