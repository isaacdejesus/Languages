#include <iostream>
#include <deque>

//double ended queue
int main()
{
    //constructors
    std::deque<char> default_que;
    //creates deque with 3 copies of x
    std::deque<char> default_que_fill(3, 'x');
    std::deque<char> copy_deque(default_que_fill);
    std::deque<char> range_deque(copy_deque.begin(), copy_deque.end());
    //rage copy arr
    char arr[] = { 'a', 'b', 'c'};
    std::deque<char> range_deque_arr(arr, arr + 3);
    // assign operator =, uses to assign one deque to another
    std::deque<char> chars_deque = range_deque_arr;
    //iterators begin() and end()
    //capacity functions
    //size() returns numbers of elements in deque
    //max_size() returns max number of elements deque can hold
    //resize() resizes deque to n, if n < currentSize deque is reduced to first n elements. rest are deleted.
    //if n > currentSize default values are added until n is reached. Can also include a value to be used to fill in extra slots
    //resize to 5 elements and make extra insertions char z
    chars_deque.resize(5, 'z');
    //empty() returns boolean if empty
    //shrink_to_fit() resizes deque to size of current elements

    //element access functions
    //[] used to assign, reassign values and to retrieve values in deque
    //[] uses indexes 0 - n
    //[] doesn't return error if [x] is not in deque
    //currently dque [a, b, c, z, z]
    //following changes first z to d resulting in [a, b, c, d, z]
    chars_deque[3] = 'd';
    std::deque<char>::size_type deque_size = chars_deque.size();
    for(int i = 0; i < deque_size; i++)
        std::cout<<chars_deque[i]<<' ';
    std::cout<<'\n';
    //at() returns a reference to element at location n if found, out of range exception if not found
    std::cout<<chars_deque.at(4);
    std::cout<<'\n';
    //front() returns reference to first element/oldest. value can be modified
    //back() returns reference to last element/newest. value can be modified
    //calling front() and back() on empty deque causes undefined 
    //current deque [a, b, c, d, z]
    chars_deque.front() = 'i';
    chars_deque.back() = 'i';
    //resulting deque [i, b, c, d, i]
    for(int i = 0; i < deque_size; i++)
        std::cout<<chars_deque[i]<<' ';
    std::cout<<'\n';

    //modifiers
    //assign() replaces and resizes deque to fit new content and deletes old content
    default_que.assign(3, 'n');  //assigns it to be size 3 with 3 ns
    default_que.assign(chars_deque.begin(), chars_deque.end());
    for(int i = 0; i < deque_size; i++)
        std::cout<<chars_deque[i]<<' ';
    std::cout<<'\n';
    //push_back() adds new element to end/newest of deque 
    //push_front() adds new element to front/oldest of deque
    //pop_back() deletes last/newest element in queue
    //pop_front() deletes the first/oldest element in queue
    //clear() deletes all content from deque
    //swap() swaps contents of two deques
    //insert() requires an iterator, can insert single, fill or range
    //erase() requires iterator, can delete single or range
    return 0;
}