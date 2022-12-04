#include <iostream>
#include <set>

//stores a unique set of values in o specific order. No, duplicates
//sets are slower than unordered_sets since elements are ordered
//set automatically sorts contents?
int main()
{
    //constructors
    //default constructor
    std::set<int> default_set;
    std::set<int> default_set_ini({1, 3, 2});
    //copy constructor
    std::set<int> copy_set(default_set_ini);
    //range
    std::set<int> range_set(default_set_ini.begin(), default_set_ini.end());
    //range can also be used to get values from arr
    int arr[] = {4, 2, 6, 8, 9, 0 };
    std::set<int> range_set_from_arr(arr, arr + 4);
    //assignment operator =, used to ini set or set one set to another set
    std::set<int> numbers_set;
    numbers_set = {8, 0, 4, 2, 4, 7, 3};
    numbers_set = range_set_from_arr;
    //iterators
    //begin() and end()
    for(std::set<int>::iterator it=numbers_set.begin(); it != numbers_set.end(); ++it)
        std::cout<<*it<<' ';
    std::cout<<'\n';
    //capacity functions
    //empty() returns bool if set is empty
    //size() returns total number of elements currently in set
    //max_size() returns max number of elements set can possibly hold

    //find() returns iterator to value if found in set or iterator to end() if not found
    std::set<int>::iterator set_iterator = numbers_set.find(8);
    std::cout<<*set_iterator<<'\n';
    //count() returns 1 if value in set or 0 if it doesn't exist
    std::cout<<numbers_set.count(8)<<'\n';
    //modifiers
    //insert() 
    numbers_set.insert(0);
    //insert a range
    numbers_set.insert(default_set_ini.begin(), default_set_ini.end());
    //can also range insert from arr
    numbers_set.insert(arr, arr+ 4);
    //erase() can delete single value, iterator or range
    numbers_set.erase(0);
    std::set<int>::iterator it = numbers_set.find(1);
    numbers_set.erase(it);
    //delete using iterator returned by find funciton
    numbers_set.erase(numbers_set.find(8));
    it = numbers_set.find(4);
    //delete range of values from 4 to end of set
    numbers_set.erase(it, numbers_set.end());
    //clear() deletes contents of set 

    for(auto item: numbers_set)
        std::cout<<item<<' ';
    return 0;
}
