#include <iostream>
#include <set>

//multiset stores values in specific order and multiples are allowed
//values are sorted resulting in multiset being slower than unordered_multiset

int main()
{
    //constructors
    //default constructor
    std::multiset<int> default_multiset;
    //set can contain multiple copies of same value and resulting set is ordered [1, 1, 2, 3]
    std::multiset<int> default_multiset_ini({3, 2, 1, 1});
    //copy constructor
    std::multiset<int> copy_multiset(default_multiset_ini);
    //range constructor
    std::multiset<int> range_multiset(default_multiset_ini.begin(), default_multiset_ini.end());
    //also works with arr
    int arr[] = {0, 1, 2, 3, 4};
    std::multiset<int> range_multiset_from_arr(arr, arr + 3);

    //assignment operator =, used to ini multiset or set one multiset to another
    std::multiset<int> numbers_multiset = {1, 2, 4, 5, 6, 7, 2, 4, 0};
    numbers_multiset = default_multiset_ini;
    //iterators begin() and ned()
    for(std::multiset<int>::iterator it = numbers_multiset.begin(); it != numbers_multiset.end(); ++it)
        std::cout<<*it<<' ';
    std::cout<<'\n';
    
    //capacity functions
    //empty() returns bool if multiset is empty or not
    //size() returns number of items in multiset
    //max_size()  

    //find() returns iterator if element found or end() if not found
    std::multiset<int>::iterator number_iterator = numbers_multiset.find(2);
    //count() returns number of entries in multiset matching value
    std::cout<<numbers_multiset.count(1)<<'\n';
    //insert() single value, or range
    numbers_multiset.insert(9);
    //erase() erase single value, using iterator or range
    numbers_multiset.erase(9);
    numbers_multiset.erase(number_iterator);
    //clear() deletes contentes of multiset
    //swap() swaps content of two multiset
    for(auto item: default_multiset_ini)
        std::cout<<item<<' ';
    std::cout<<'\n';
    return 0;
}