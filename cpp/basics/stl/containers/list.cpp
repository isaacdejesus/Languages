//double linked list
#include <iostream>
#include <list>

int main()
{
//constructors
std::list<int> emptyList;   //declares empty list
//fill constructor
std::list<int> filledList(6, 77);  //creates list with 77 repeated 6 times 
std::list<int> filledList_with_zeros(6); //creates a list with 6 zeroes
//range constructor
std::list<int> rangedList(filledList.begin(), filledList.end());
//copy constructor
std::list<int> copy_constructor(filledList); 

//can use range constructor to copy elements from array to list
int arr [] = {3, 4, 5, 6, 7, 9};
std::list<int> copy_of_array(arr, arr + sizeof(arr)/sizeof(int));

//use iterator to loop through nodes
for(std::list<int>::iterator it = copy_of_array.begin(); it != copy_of_array.end(); it++)
    std::cout << *it << ' ';
std::cout << '\n';

//assignment operator =, allows you to set one list equal to another
std::list<int> assigned_list = copy_of_array; 

//empty(), size()
//first and last elements can be accessed
std::cout<<"At the front of the list we have: "<<copy_of_array.front() << '\n';
std::cout<<"At the back of the list we have: "<<copy_of_array.back() <<'\n';

//modifiers
//assign- replaces contents of list with new elements and resizes accordingly
copy_of_array.assign (9, 0); //change content of list to now contain 9 zeroes
for(std::list<int>::iterator it = copy_of_array.begin(); it != copy_of_array.end(); it++)
    std::cout << *it << ' ';
std::cout << '\n';

//assign with range
copy_of_array.assign (arr, arr + 6);
for(std::list<int>::iterator it = copy_of_array.begin(); it != copy_of_array.end(); it++)
    std::cout << *it << ' ';
std::cout << '\n';

//push_front() and push_back() add elements to front/back
//pop_front() and pop_back() delete elements from front/back
//clear()
//insert() inserts element/s before elements at specified position
std::list<int>::iterator it = copy_of_array.begin(); //set it to point to first element of list
++it;
++it;
//it points to 3rd element. insert 0 at position 3
copy_of_array.insert(it, 0);
//can also insert using fill
copy_of_array.insert(it, 3, 1); //insert 3 1's before position 3
//can also use range to insert
--it;
--it;
--it;
--it;
copy_of_array.insert(it, filledList.begin(), filledList.end());
for(std::list<int>::iterator it = copy_of_array.begin(); it != copy_of_array.end(); it++)
    std::cout << *it << ' ';
std::cout << '\n';

//erase, delete one element or a range
it = copy_of_array.begin();
++it;
++it;
//delete one 77
//copy_of_array.erase(it);
//delete range
std::list<int>::iterator it2 = copy_of_array.end();
--it2;
--it2;
--it2;
--it2;
copy_of_array.erase(it, it2);
for(std::list<int>::iterator it = copy_of_array.begin(); it != copy_of_array.end(); it++)
    std::cout << *it << ' ';
std::cout << '\n';

//splice, transfer elements from x and insert at pos

//sort() and unique(), reverse()
copy_of_array.push_back(7);
copy_of_array.sort();
for(std::list<int>::iterator it = copy_of_array.begin(); it != copy_of_array.end(); it++)
    std::cout << *it << ' ';
std::cout << '\n';
copy_of_array.unique();
for(std::list<int>::iterator it = copy_of_array.begin(); it != copy_of_array.end(); it++)
    std::cout << *it << ' ';
std::cout << '\n';
copy_of_array.reverse();
for(std::list<int>::iterator it = copy_of_array.begin(); it != copy_of_array.end(); it++)
    std::cout << *it << ' ';
std::cout << '\n';
//remove(), delete specified value
copy_of_array.remove(5);
for(std::list<int>::iterator it = copy_of_array.begin(); it != copy_of_array.end(); it++)
    std::cout << *it << ' ';
std::cout << '\n';


return 0;
};
