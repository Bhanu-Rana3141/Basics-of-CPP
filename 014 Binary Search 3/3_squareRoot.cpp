#include<iostream>
#include<math.h>
using namespace std;

// Concept of search space

int squareRoot(int arr[], int num){
    int s = 0;
    int e = num-1;
    int mid = s+(e-s)/2;

    int ans = -1;
    while(s <= e){
        if(mid*mid == num){
            return mid;
        }
        else if(mid*mid > num){
            e = mid-1;
        }
        else if(mid*mid < num){
            ans = mid;
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int main() {
    int num;
    cout << "Enter num: ";
    cin >> num;

    int arr[num];
    for(int i=0; i<num; i++){
        cin >> arr[i];
    }

    /* TC -> O(1) constant time
    Using inbuilt function
    cout << sqrt(num);
    */

    // Without using inbuilt function
    int ans = squareRoot(arr,num);
    cout << "Ans: " << ans;
    return 0;
}