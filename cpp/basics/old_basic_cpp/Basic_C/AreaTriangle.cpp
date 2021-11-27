#include<iostream>
using namespace std;

float areaOfTriangle(int base, int height);
int main()
{
    int myBase, myHeight;
    float myArea;
    cout<<"Enter base and height of the triangle: "<<'\n';
    cin>>myBase>>myHeight;
    cout<<'\n';
    myArea=areaOfTriangle(myBase, myHeight);
    cout<<"The area of your triangle is: "<<myArea<<'\n';
    return 0;
}

float areaOfTriangle(int base, int height)
{
    float area=0;
    //typecast result as floa
    area=(float)(base*height)/2;
    return area;
}