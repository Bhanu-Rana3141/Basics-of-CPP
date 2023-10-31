#include<iostream>
using namespace std;

// Counting 1 to N   -> Head Recursion

void print_counting(int n){

//Base Case
    if(n==0){  
        return;
    }

// Recursive Relation  
   print_counting(n-1);

// Processing
   cout<<n<<" ";

   

}

/* USING PARAMERTERISED WAY ->by using extra varible
void print_counting(int n, int temp){
    if(temp>n)
        return;
    cout<<temp<<endl;
    print_counting(n,temp+1);
}
*/

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    print_counting(n);


    // print_counting(n,1);  -> extra parameter
    return 0;
}