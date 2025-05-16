#include <iostream>
#include <list>

//list are double linked list. allow constant time insertion and deletion
//slower direct access
int main()
{
    //constructors
    std::list<int> default_list;
    std::list<int> default_list_ini({2, 4, 3, 5, 6});
    std::list<int> fill_list(3, 0);  //creates list with 3 0s
    std::list<int> copy_list(fill_list);
    std::list<int> range_list(default_list_ini.begin(), default_list_ini.end());
    //assign operator = , to ini or to set list to another list
    std::list<int> numbers_list = {0, 1, 2};
    numbers_list = default_list_ini;

    //iterators begin() and end()
    for(std::list<int>::iterator it = numbers_list.begin(); it != numbers_list.end(); ++it)
        std::cout<<*it<<' ';
    std::cout<<'\n';

    //capacity functions
    //empty() return bool is list empty
    //size() returns number of elements in list
    //max_size() returns max number of elements list can contain

    //element access
    //front() returns direct reference to first element in container/head
    //back() return direct reference to last element in container/tail
    //since they are direct reference value can be changed
    //current list [2, 4, 3, 5, 6]
    std::cout<<numbers_list.front()<<'\n';  //2
    std::cout<<numbers_list.back()<<'\n';   //6

    //modifiers
    //assign() assigns new content to list by replacing contents and resizing as needed
    default_list.assign(7, 0);  //assign list to contain 7 0s
    default_list.assign(numbers_list.begin(), numbers_list.end());
    //push_front() inserts new value at head of list
    //pop_front() deletes element from head
    //push_back() insert new value at tail
    //pop_back() deletes last element 
    //clear() deletes all elements fromtlist
    //resize() resizes element to n. 
    //if currentSize > n, list resizes to first n elements and deletes the rest
    //if currentSize < n, extra elements are added to reach n. 
    //extra parameter can be passed as value to use to fill extra spots
    numbers_list.resize(7, 0);   //resize to 7 values and use 0 as filler
    //insert() requires an iterator, can insert a single value, filled(multiple copies) or range of values
    //erase() requires an iterator, can erase single element or range of values

    //operations on lists
    //splice() requires iterator. Takes content from aother list and inserts at iterator. Contents deleted from other list
    std::list<int>::iterator it = numbers_list.begin();
    it++;
    //numbers_list contains [2, 4, 3, 5, 6], it points to index 1
    std::list<int> nines = {9, 9};
    numbers_list.splice(it, nines);  //copies entire list of nines into numbers_list
    //copies a single element from another list
    //takes insert iterator, donor list and iterator pointing to donor element
    nines.splice(nines.begin(), numbers_list, it); //
    //can splice a range
    //iterator to insert, donor list, iterator to start, iterator to end
    nines.splice(nines.begin(), numbers_list, numbers_list.begin(), numbers_list.end());
    //sort()
    nines.sort();
    //reverse()
    nines.reverse();
    //unique() removes duplicates
    nines.unique();
    //merge() merges 2 sorted lists
    //remove() deletes all instances from list with given value
    //remove_if() takes function expression and deletes elements matching expression result
    for(auto item: nines)
        std::cout<<item<<' ';
    std::cout<<'\n';
    return 0;
}