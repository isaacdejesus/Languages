//double ended queue
#include <iostream>
#include <deque>
int main()
{
    //constructors
    std::deque<int> default_deque;
    std::deque<int> fill_deque(4);
    std::deque<int> range_deque(fill_deque.begin(), fill_deque.end());

    //range to copy from array
    int arr [] = {0, 2, 4, 6, 7};

    std::deque<int> copy_of_array(arr, arr + sizeof(arr)/sizeof(int));

    for(std::deque<int>::iterator it = copy_of_array.begin(); it !=copy_of_array.end(); ++it)
        std::cout<<' '<< *it;
    std::cout<<'\n';
    
    //size(), empty(), clear()
    //element access: [], at, front(), back()
    int size_of_deque = copy_of_array.size();
    for(int i = 0; i< size_of_deque; i++)
        std::cout<<copy_of_array[i]<<' ';    //use [] to access elements
    std::cout<<'\n';

    //print element at position 2
    std::cout<<copy_of_array.at(2)<<'\n';

    //push_back() and push_front() add elements to front/back
    //pop_back() and pop_front() to delete from front/back
    //assign - assigns replaces old values with assigned values
    copy_of_array.assign(7, 5);     //assign deque 7 fives
    for(std::deque<int>::iterator it = copy_of_array.begin(); it !=copy_of_array.end(); ++it)
        std::cout<<' '<< *it;
    std::cout<<'\n';
    std::deque<int>::iterator it = fill_deque.begin();
    //assign values from fill_deque
    copy_of_array.assign(it, fill_deque.end() - 2);
    for(std::deque<int>::iterator it = copy_of_array.begin(); it !=copy_of_array.end(); ++it)
        std::cout<<' '<< *it;
    std::cout<<'\n';
    //assign from array
    copy_of_array.assign(arr, arr + 5);
    for(std::deque<int>::iterator it = copy_of_array.begin(); it !=copy_of_array.end(); ++it)
        std::cout<<' '<< *it;
    std::cout<<'\n';
    
    //erase
    //erase a single element
    copy_of_array.erase(copy_of_array.begin() + 1);   //delete second element
    for(std::deque<int>::iterator it = copy_of_array.begin(); it !=copy_of_array.end(); ++it)
        std::cout<<' '<< *it;
    std::cout<<'\n';
    //use range to delete the middle two elements
    copy_of_array.erase(copy_of_array.begin() + 1, copy_of_array.end() - 1);
    for(std::deque<int>::iterator it = copy_of_array.begin(); it !=copy_of_array.end(); ++it)
        std::cout<<' '<< *it;
    std::cout<<'\n';
    
    //insert element/s before specified location
    copy_of_array.insert(copy_of_array.begin() + 1, 99);
    //insert using fill
    copy_of_array.insert(copy_of_array.begin() + 1, 2, 66);
    for(std::deque<int>::iterator it = copy_of_array.begin(); it !=copy_of_array.end(); ++it)
        std::cout<<' '<< *it;
    std::cout<<'\n';
    //insert using range
    copy_of_array.insert(copy_of_array.begin() + 1, fill_deque.begin(), fill_deque.end());
    for(std::deque<int>::iterator it = copy_of_array.begin(); it !=copy_of_array.end(); ++it)
        std::cout<<' '<< *it;
    std::cout<<'\n';


    return 0;

}
