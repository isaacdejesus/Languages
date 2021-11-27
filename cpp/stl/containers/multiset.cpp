#include <iostream>
#include <set>

//store elements in order and multiple elements can have multiple equivalent values
//automaticaly sorts elements input to the set
int main()
{
    //constructors
    std::multiset<int> default_constructor;
    //range from array
    int arr [] = {2, 4, 5, 6, 2, 6 , 3, 5};
    std::multiset<int> copy_of_array(arr, arr + 8);
    //copy
    std::multiset<int> copy_of_multiset(copy_of_array);
    for(std::multiset<int>::iterator it = copy_of_array.begin(); it!= copy_of_array.end(); it++)
        std::cout<<' '<< *it;
    std::cout<<'\n';

    //empty() size() clear()
    //count() returns number of matches to given value
    //find() searches for element and returns iterator to location
    //insert
    copy_of_array.insert(0);
    copy_of_array.insert(3);
    //range
    copy_of_array.insert(arr, arr + 4);
    for(std::multiset<int>::iterator it = copy_of_array.begin(); it!= copy_of_array.end(); it++)
        std::cout<<' '<< *it;
    std::cout<<'\n';

    return 0;
}
