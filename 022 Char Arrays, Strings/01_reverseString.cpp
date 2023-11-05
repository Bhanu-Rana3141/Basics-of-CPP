#include<iostream>
#include<algorithm>
using namespace std;

void reverse(char name[],int n){
    int s=0;
    int e=n-1;

    while(s <= e){
        swap(name[s++], name[e--]);
    }
}

int getLength(char name[]){
    int count = 0;
    for(int i=0; name[i] != '\0'; i++){
        count++;
    }
    return count;
}

int main() {
   
    cout << "Enter string: ";
    char name[20];
    cin >> name;

    int length = getLength(name);
    cout << "Lenght: " << length << endl;
    
    // Using inbuilt function
    reverse(name,name+length);
    cout << "name: "<<name;
    
    // reverse(name,length);
    // cout<<"name: "<<name;
    return 0;
}