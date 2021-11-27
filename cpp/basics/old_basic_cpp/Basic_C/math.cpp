#include<iomanip>
#include<math.h>
#include<cmath>
#include<iostream>

using namespace std;


float rootOfQuadEq(int a, int b, int c);
int main()
{
    int myA, myB, myC;
    cout<<"Enter values for 'a', 'b' and 'c': "<<'\n';
    cin>>myA>>myB>>myC;
    cout<<'\n';

    //calling in rootofquadfunction
    cout<<rootOfQuadEq(myA, myB, myC);
}

float rootOfQuadEq(int a, int b, int c)
{
    float r;
    r=(-b+sqrt(b*b-4*a*c))/(2*a);
    return r;
}


if() {
    kflkjf
}