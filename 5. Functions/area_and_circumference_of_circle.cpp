#include<iostream>
using namespace std;

float circleArea(int radius,float pi){
    float area = pi*radius*radius;
    return area;
}

float circleCircumference(int radius , float pi){
    float circumference = 2*pi*radius;
    return circumference;
}

int main() {
    int radius;
    cout<<"Enter radius: ";
    cin>>radius;

    const float pi =3.14;

   cout<<"Area: "<<circleArea(radius,pi)<<endl;
   cout<<"Circumference: "<<circleCircumference(radius,pi);


    
    return 0;
}