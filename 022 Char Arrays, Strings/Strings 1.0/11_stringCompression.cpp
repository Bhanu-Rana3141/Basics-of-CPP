#include<iostream>
#include<vector>
using namespace std;

int stringCompression(vector<char>& chars) {

    int i = 0;
    int n = chars.size();
    int ansIndex = 0;
 
    while(i < n) {
        int j = i+1;
        while(j < n && chars[j] == chars[i]) {
            j++;
        }

        chars[ansIndex++] = chars[i];

        int count = j-i;
        if(count > 1) {
            string cnt = to_string(count);
            for(auto ch : cnt) {
                chars[ansIndex++] = ch;
            }
        }

        i = j;
    }
    return ansIndex;
}

int main()
{   
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<char> chars(n);
    for(int i = 0; i < n; i++) {
        cin >> chars[i];
    }

    int cnt = stringCompression(chars);

    cout << "cnt: " << cnt << endl;
    for(auto it : chars) {
        cout << it << " ";
    }

    return 0;
}