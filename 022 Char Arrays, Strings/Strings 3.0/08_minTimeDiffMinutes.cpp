/*
TC : O(n log n) -> sorting
SC : O(n) -> using minutes vector
*/

#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<limits.h>
using namespace std;

int main() {

    vector<string> timePoints =  {"23:59", "00:10",  "10:15", "13:15", "17:20", "18:00", "19:47"};

    // 1. convert hours into minutes    TC : O(n)
    vector<int> minutes;

    for(int i=0; i<timePoints.size(); i++) {
        int hours = stoi(timePoints[i].substr(0,2));
        int min = stoi(timePoints[i].substr(3,2));
        int totalMinutes = hours*60 + min;
        minutes.push_back(totalMinutes);
    }

    // 2. sort minutes array to find min minutes difference, this could be done without sorting but in that case 1 element has to be compared with all other elements and which will result in TC: O(n^2) but by using sorting this can be reduced to O(nlogn)

    sort(minutes.begin(), minutes.end());

    // 3. find min by calculating diff  TC: O(n)
    int mini = INT_MAX;
    int n = minutes.size();

    for(int i=0; i<n-1; i++) {
        int diff = minutes[i+1] - minutes[i];
        mini = min(mini, diff);
    }

    // 4. This is the game EDGE CASE
    int lastDiff1 = (minutes[0] + 1440) - minutes[n-1];
    int lastDiff2 = minutes[n-1] - minutes[0];
    int lastDiff = min(lastDiff1, lastDiff2);

    mini = min(lastDiff, mini);

    cout << endl;
    cout << "Minimum time difference : " << mini;
    cout << endl << endl;

    return 0;
}