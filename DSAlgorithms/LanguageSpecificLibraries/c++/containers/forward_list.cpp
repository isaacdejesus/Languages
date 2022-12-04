#include <iostream>
#include <forward_list>
 //forward_list are single linked lists with constant time insertion and removals
int main()
{
    //constructors
    std::forward_list<int> default_list;
    std::forward_list<int> default_list_ini({1, 2, 3});
    std::forward_list<int> copy_list(default_list_ini);
    std::forward_list<int> fill_list(7, 0);  //creates list wit 7 0s
    std::forward_list<int> range_list(copy_list.begin(), copy_list.end());
    //assign operator =, used to ini list or set list to copy other list
    std::forward_list<int> numbers_list = {1, 2, 3, 4, 5};
    default_list = numbers_list;
    
    //iterators begin() and end()
    for(std::forward_list<int>::iterator it = numbers_list.begin(); it != numbers_list.end(); ++it)
        std::cout<<*it <<' ';
    std::cout<<'\n';
    //empty()
    //max_size()
    //front() returns direct reference to first element/head and value can be modified
    std::cout<<numbers_list.front()<<'\n';
    //assign() replaces contents of list and resizes to fit new content
    default_list.assign(3, 0); //assign it to containe 3 0s
    default_list.assign(numbers_list.begin(), numbers_list.end());
    default_list.assign({0, 3, 2});
    //push_front() adds element to front of list/head
    //pop_front() deletes element from front/head
    //clear() deletes all contents
    //resize() resizes list to size n
    //if currentSize < n, resize to first n elements, rest are deleted
    //if currentSize > n, filler elements are added to reach size n. extra parameter can passed to be used as filler
    numbers_list.resize(7, 0);  //resizes to 7 and uses 0 as filler
    //insert_after() requires iterator to insert location and can insert single value, range or list
    numbers_list.insert_after(numbers_list.begin(), 9);
    numbers_list.insert_after(numbers_list.begin(), default_list_ini.begin(), default_list_ini.end());
    numbers_list.insert_after(numbers_list.begin(), {5, 5, 5});
    //erase_after() requires iterator, can delete single value or range
    numbers_list.erase_after(numbers_list.begin());  //delete single value after iterator
    default_list.erase_after(default_list.begin(), default_list.begin());

    //sort()
    //reverse()
    //merge() merges 2 sorted lists
    //unique() deletes duplicates
    numbers_list.unique();
    //splice_after() transfers elements from another list after iterator
    numbers_list.splice_after(numbers_list.begin(), default_list);   //inserts entire contents of default after iterator
    //can also splice a single element or a range
    //remove() deletes all instance of a given value
    //remove_if() deletes values if they match expression/function
    return 0;
}