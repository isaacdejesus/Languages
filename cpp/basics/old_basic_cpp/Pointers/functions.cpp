#include <iostream>
#include <string>
/*Review:
    datatype *variable_name declares a pointer
    int *pointer=nullptr; to avoid pointing to random memory
    &variable; gives memory address of var
    pointer; will just give you a memory address
    *pointer; gives info stored in var to which pointer points to
    be sure to deallocate before reusing pointers delete []pointer to avoid memory leaks
    set pointer to null prior to reuse to avoid dangling pointer
  */

std::string display(std::string nameIn);
int main()
{
    std::string *pointer=nullptr;
    std::string array[]={"First", "Second", "Third", "Fourth", "Sixth", "Seveth"};
    //setting pointer to array
    //int *pointer=array;
    pointer=array;
    std::cout<<"Currently the pointer is set to first index of array: "<<*pointer<<'\n';
    //pointer++ moves the pointer to the next index
    pointer++;
    std::cout<<"The pointer is not set to the second index of the array: "<<*pointer<<'\n';

    //Here we deallocate and create a var to store a string
    delete pointer;
    std::string name="";
    std::cout<<"Enter your name: "<<'\n';
    std::cin>>name;

    //declare pointer to function
    std::string (*new_ptr)(std::string);
    //initialise the function
    new_ptr=display;
    //function call
    std::cout<<new_ptr(name);



    return 0;
}
std::string display(std::string nameIn)
{
  std::string name="";
  name="Hello, " + nameIn;
  return name;
}