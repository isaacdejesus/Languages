#include <iostream>
#include <vector>
//vectors are dynamic arrays. Elements stored contigiously in memory.
//Insertions are amortized constant time (1) since vector resizes/doubles in size

int main()
{
    //constructors
    //default constructor creates empty vector
    std::vector<int> default_constructor();
    //default constructor can also be ini at declaration time
    std::vector<int> default_constructor_ini = {1, 3, 5, 7, 9};
    //fill constructor - ini constructor of n size with n copies of given element
    std::vector<int> fill_constructor(3, 0);  //creates vector of 3 elements with value of 0
    //range constructor ini a new vector with elements from existing vector using iterators [start, end)
    //not including last element. Here we start iterator at fill_constructor[1] to fill_constructor[end + 1]
    std::vector<int> range_constructor(fill_constructor.begin() + 1, fill_constructor.end());
    //range constructor can be used to create new vector from array
    int numbers_arr[] = {1, 3, 5, 7, 9};
    //makes a vector with all elements from numbers_arr
    std::vector<int> range_constructor_from_array(numbers_arr, numbers_arr + sizeof(numbers_arr) / sizeof(int));
    //Can also copy range from array. Here we copy first 3 elements from arr
    std::vector<int> range_from_array(numbers_arr, numbers_arr + 3);
    //copy constructor - makes a copy of existing vector
    std::vector<int> copy_constructor(range_constructor);

    //------------------------------------------------------------
    //Member functions
    // = operator, replaces current elements and resizes to fit elements from another vector
    //replaces [0,0] with [1, 3, 5, 7, 9]
    copy_constructor = default_constructor_ini;

    //Iterators 
    //begin() returns a random access iterator to beginning to container
    //end() returns iterator to last element + 1;
    //if vector is empty end() returns same loc as begin()
    for(std::vector<int>::iterator it = default_constructor_ini.begin(); it != default_constructor_ini.end(); ++it)
        std::cout<<*it<<" ";
    std::cout<<'\n';
    //rbegin() returns iterator at end of vector and iterates backwards, towards beginning of vector
    std::vector<int>::reverse_iterator rit = default_constructor_ini.rbegin();
    //rend() returns iterator to element before first, 

    //capacity 
    //size() returns length of arr
    int size_of_vector = default_constructor_ini.size();
    //max_size() returns max possible size of vector...Not the current max size of vector
    //capacity() retuns max size/ number of elements vector can accomodate. It is not current size/number of elements in vector
    //empty() returns bool if vector is empty
    //reserve() request chance in vector capacity to hold at least n elements
    //resize() if new size is less than current size, extra elements are deleted
    //if new size is greater than current, elements are added to end to reach size n
    //an extra parameter val can be passed, used to fill empty slots to reach size n
    //here we resize from 3 elements to 10 and set fill vlaue to 0
    range_from_array.resize(10, 0);
    //shrink_to_fit() request capacity to  fit size;

    //element access
    //[] can be used to access elements of a vector
    //at() can be used to access elements of a vector
    //front() access to first element of vector
    //back() access to last element of vector

    //modifiers
    //assign()
    std::vector<char> chars_vector;
    //assign(7, 0); changes contents of current vector to 7 elements all being 'r' 
    chars_vector.assign(7,'r');
    //assign(start, end) changes vector to contain range of elements from another vector
    std::vector<char> chars_vector2 = {'a', 'b', 'c', 'd', 'e'};
    chars_vector.assign(chars_vector2.begin(), chars_vector2.end());
    //can also be used to assign range values from array
    char chars_arr[] = { 'x', 'y', 'z', 'k'};
    chars_vector.assign(chars_arr, chars_arr + 3);
    //push_back() adds element to end
    //pop_back() deletes last element
    //insert() insert element(s) at indicated iterator
    std::vector<char>::iterator it = chars_vector.begin();
    it++;
    //insert(start, value) '.' at index 1
    chars_vector.insert(it, '.');
    it = chars_vector.begin();
    //insert(start, #ofcopies, value), fill insert #ofcopies of value
    //insert $ 3 times
    chars_vector.insert(it, 3, '$');
    //insert(start, range_start, range_end), inserts range of elements from other vector at start
    it = chars_vector.begin();
    //inserts chars_vector2 at start of chars_vector
    chars_vector.insert(it, chars_vector2.begin(), chars_vector2.end());
    //erase() deletes a single element or range of elements [first, last), not including last
    //current chars_vector = [a, b, c, d, e, $, $, $, ., y, z]
    //deletes the 5th element == e
    chars_vector.erase(chars_vector.begin() + 4);
    //erase the first 3 elements a, b, and c
    chars_vector.erase(chars_vector.begin(), chars_vector.begin() + 3);
    //clear() deletes all elements and sets size to 0
    //swap(), swaps contents of two vectors
    std::vector<char> vector_of_a(3, 'a');  //creates [a, a, a]
    std::vector<char> vector_of_b(2, 'b'); //creates [b, b]
    //after swap vector_of_a = [b, b] and vector_of_b = [a, a, a]
    vector_of_a.swap(vector_of_b);
    for(auto element: vector_of_b)
        std::cout<<element<<" ";
    return 0;
}