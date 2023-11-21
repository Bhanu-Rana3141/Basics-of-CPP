#include <iostream>
using namespace std;

/* Approach 1 -> By calculating frequency of each element of array and the element which is present only once is returned

int unique(int arr[], int n){
    for(int i=0; i<n; i++){
        if(arr[i] == -1){
            continue;
        }
        int count = 1;
        for(int j=i+1; j<n; j++){
            if(arr[i] == arr[j]){
                count++;
                arr[j] = -1;
            }
        }
        cout << arr[i] << " : " << count << endl;
        if(count == 1){
            return arr[i];
        }
    }
}
*/

/* Approach 2 -> By using array manipulation, here we will compare with each element of array and by using nested
loops and assing -1 wherever values will be repeated and then at all positions -1 will be assigned except 1 position
and element at that position will be unique element

int unique(int arr[], int n){
    for(int i=0; i<n; i++){
        if(arr[i] == -1){
            continue;
        }
        for(int j=i+1; j<n; j++){
            if(arr[i] == arr[j]){
                arr[i]=arr[j]=-1;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(arr[i] > -1){
            return arr[i];
        }
    }
}
*/

// Approach 3 -> Optimised approach using XOR
int unique(int arr[],int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans ^= arr[i];
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the n of the array: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Unique element: " << unique(arr,n);

    return 0;
}
