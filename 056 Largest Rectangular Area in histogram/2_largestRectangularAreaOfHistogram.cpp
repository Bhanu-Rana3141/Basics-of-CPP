// TC - O(N^2) && SC - O(1)

#include<iostream>
#include<limits.h>
using namespace std;

int calculateLeft(int *arr, int i) {

    int j = i - 1;
    int width = 0;

    while(j >= 0) {
        if(arr[i] <= arr[j]) {
            width++;
            j--;
        }
        else {
            break;
        }
    }
    return width;
}

int calculateRight(int *arr, int i, int n) {

    int j = i + 1;
    int width = 0;

    while(j < n) {
        if(arr[i] <= arr[j]) {
            width++;
            j++;
        }
        else {
            break;
        }
    }
    return width;
}

int maxArea(int *arr, int n) {

    int maxArea = INT_MIN;
    
    for(int i=0; i<n; i++) {

        if(i == 0) {
            int width = calculateRight(arr, i, n);
            width += 1;
            int area = arr[i] * width;
            maxArea = max(maxArea, area);
            cout << "element: " << arr[i] << " , Area : " << area << endl;
            continue;
        }

        if(i == n-1) {
            int width = calculateLeft(arr, i);
            width += 1;
            int area = arr[i] * width;
            maxArea = max(maxArea, area);
        }

        int leftWidth = calculateLeft(arr, i);
        int rightWidth = calculateRight(arr, i, n);

        int totalWidth = leftWidth + rightWidth + 1;

        int area = arr[i] * totalWidth;
        
        cout << "element: " << arr[i] << " , area: " << area << endl; 

        maxArea = max(maxArea, area);
        
    }
    return maxArea;
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter array elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // EDGE CASE
    if(n == 1) {
        cout << "Max Area: " << arr[0] * 1;
        return 0;
    }
    
    int ans = maxArea(arr, n);

    cout << "Max area : " << ans;

    return 0;
}