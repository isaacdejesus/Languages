#include<iostream>
using namespace std;
int main()
{
    int *arr;
    int arrSize;
    
    cout<<"Enter array size: "<<'\n';
    cin>>arrSize;
    cout<<'\n';
    cout<<"Creating array of size "<<arrSize<<'\n';
    arr=new int[arrSize];
    
    for(int i=0; i<arrSize; i++)
    {
        arr[i]=i;
        cout<<arr[i];
    }
    return 0;
}
