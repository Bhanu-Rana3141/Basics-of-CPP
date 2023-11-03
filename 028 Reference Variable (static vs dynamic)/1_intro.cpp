#include<iostream>
using namespace std;

int main() {
   /* int i = 5;
    // creating reference variable
    int& j = i;

    cout<<endl<<endl;

    cout<<i<<endl;
    cout<<j<<endl;

    i++;
    cout<<j<<endl;

    j+=5;
    cout<<i<<endl;

    cout<<endl<<endl;
*/

    // Dynamic memory allocation of variable
    int *num = new int;
    cout << "Enter num: ";
    cin >> *num;

    cout << "num: " << *num << endl;
    cout << "Address: " << num;

    
    return 0;
}