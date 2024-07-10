#include<iostream>
#include<vector>
using namespace std;

void f(int i, int &n, vector<int>& arr, int& k, int& cnt, vector<int> temp) {

    if(i == n) {
        int sum = 0;
        for(auto it : temp) {
            sum += it;
        }

        if(sum == k) {
            cnt++;
            for(auto it : temp) {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    temp.push_back(arr[i]);
    f(i + 1, n, arr, k, cnt, temp);
    temp.pop_back();
    f(i+1, n, arr, k, cnt, temp);
}

int main()
{
    int n = 3;
    vector<int> arr = {1, 2, 1};
    int k = 2;

    int cnt = 0;
    vector<int> temp;

    f(0, n, arr, k, cnt, temp);

    cout << "cnt : " << cnt;

    return 0;
}