#include <iostream>


int main()
{
    char arr[]={'f', 'u', 'c', 'k'};
    for(char i: arr)
        std::cout<<i;
    std::cout<<'\n';

    //foreach loop is not size dependent, the var takes on the value stored at each index instead of the index
    //example will increase value stored in indexes and print out array
    int array[]={0,1,2,3,4,5};
    for(auto i: array)
        std::cout<<++i;
    //the following will pass values stored in indexes by reference causing permanent changes to values
    for(auto &i: array)
        ++i;
    std::cout<<'\n';
    //print out modified array
    for(auto i: array)
        std::cout<< i;
    return 0;
}