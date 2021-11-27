#include <iostream>

    /*  Regular variables and arrays are created in the stack
        Size of arrays declared in the stack can not be modified
        Pointers and dynamic arrays allocate memory in the heap, allowing us to modify size after declaration
    */ 
int main()
{
    //declaring regular variable in the stack.
    int var=7;
    //* is the deferrence operator-Gives info stored in variable pointed to by pointer
    //& is the reference operator- Gives address of variable
    //& can be used to create aliases of variable. See below
    int &var_alias=var;
    var_alias++;
    //var_alias acts as another name for var. Changes made to one reflect on the other
    std::cout<<"Value stored in var is: "<<var<<'\n';
    std::cout<<"Value stored in var_alias is: "<<var_alias<<'\n';
    //declaring a pointer which allocates memory in the heap
    //*always initialize pointers, use nullptr is there is nothing to point to yet
    int *pointer=nullptr;
    //setting pointer to var's address
    pointer = &var;

    /*Print statements to check outputs */

    std::cout<<"&pointer will print out the address at which the pointer itself is stored: "<<&pointer<<'\n';
    std::cout<<"pointer will print out the address stored in pointer/address of var to which pointer points: "<<pointer<<'\n';
    std::cout<<"*p will print out value stored in var to which pointer points to: "<<*pointer<<'\n';
    std::cout<<'\n';
    //Creating dynamic array with use input
    int size;
    int *array=nullptr;
    std::cout<<" Enter a size for the array: "<<'\n';
    std::cin>>size;
    //allocates memory in heap
    array=new int[size];
    //alternatively int *array= new int[size]
    //array can then be used as usual 
    array[0]=777;
    std::cout<<"Value stored in first index of dynamic array is: "<<array[0]<<'\n';
    //dynamic arrays stored in heap can be modidied but must first be deallocated
    //[] only needed because it is an array
    //*failure to deallocate will lead to memory leak. Inability to access memory
    delete []array;
    //*be sure to set pointer to null before usage, else it becomes a dangling pointer
    //*dangling pointers point to deallocated memory
    array=nullptr;
    //we can now reuse the array and give it a different size and store new data in it
    array= new int[7];
    array[0]=7;
    std::cout<<"Value stored in the first index of recycled array is: "<<array[0]<<'\n';
    //

    return 0;
}