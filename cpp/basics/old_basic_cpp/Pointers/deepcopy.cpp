#include <iostream>

int main()
{
    //declare two pointers;
    int *original=nullptr;
    int *copy=nullptr;

    //create array
    original= new int[4];
    //populate array
    for(int i=0; i<4; i++)
        {
        original[i]=i;
        std::cout<<original[i];
        }
    //The following assignment creates a shallow copy of the array
    copy=original;
    //The above results in dangling pointer if one of the arrays/pointers is deallocated because they both point to the same address
    //Problem can be solved by creating a deep copy of the original array into the copy array
    //Arrays contain the same info but are stored at different addresses
    delete [] copy;
    copy=nullptr;
    copy= new int[4];
    //Now copy is its own array with own address
    for(int i=0; i<4; i++)
        copy[i]=original[i];
    //Now both arrays/pointers point to different addresses and changes made to one does not affect the other
    return 0;
}