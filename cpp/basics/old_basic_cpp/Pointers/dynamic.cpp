#include <iostream>
#include <string>
int main()
{
    //declares a regular var
    int var=9;
    //allocates memory for pointer but is not dynamic
    int *pointer=nullptr;
    //therefore, the following is not dynamic.
    pointer=&var;
    //deallocate
    //delete pointer;
    pointer=nullptr;

    /*Dynamic variables and arrays */
    //declares dynamic variable with memory allocated in the heap
    //dynamic var is un-named, meaning the pointer doesn't point to another var.
    //a dynamic variable simply allocates memory and stores the address in the pointer
    //as a result we can create, access and delete a variable during run time 
    pointer = new int;
    //dynamic var can be accessed as follows
    *pointer=8;
    //variable can be re-allocated but must first be deallocated to avoid memory leaks
    //memory leaks happen when pointer points to a new address making information stored at previous address unaccessible.
    delete pointer;
    //failure to set pointer to null will cause danling pointer
    //dangling pointer points to data that no longer exists
    pointer= nullptr;
    //reallocate to make a dynamic array
    pointer = new int[7];
    //to deallocate dynamic array
    delete []pointer;
    pointer=nullptr;


    /* dynamic arrays*/
    //program below creates dynamic array with use input
    int size=0;
    std::string *stringPointer=nullptr;
    std::cout<<"Enter size of array: "<<'\n';
    std::cin>>size;
    stringPointer=new std::string[size];

    //data can be stored into array in various ways
    /* One: */
    //Will store Joe into the first index
    *stringPointer="joe";
    //Will move to next index and store another string
    stringPointer++;
    *stringPointer="isaac";
    //need to return to first index to avoid errors in method #3
    stringPointer--;

    /* Two: */
    stringPointer[0]="Teresa";
    stringPointer[1]="Triss";
    
    /* Three: */
    std::string nameIn;
    for( int i=0; i<size; i++)
        {
            std::cout<<"Enter a name: "<<'\n';
            std::cin>>nameIn;
            stringPointer[i]=nameIn;
        }
    
    return 0;
}