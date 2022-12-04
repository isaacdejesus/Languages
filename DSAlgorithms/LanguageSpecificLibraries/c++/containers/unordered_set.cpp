#include <iostream>
#include <unordered_set>
//unordered set - stores unique values/ no duplicates in no particular order. 
//key = value. Immutable, can only insert and delete
//stored hashlike for faster retrieval than regular set
//[1, 2, 3, 4, 5] -> not stored sequentially in memory in unordered_set
//[1, 2, 3, 4, 5] -> stored togethe in memory in set

int main()
{

//constructor()
//default constructor builds empty set
std::unordered_set<int> default_set;
//default constructor can be ini at declaration
//notice duplicate 1 will not be stored in set
std::unordered_set<int> default_set_ini = {1, 2, 3, 1};
//copy constructor() makes copy of another vector
std::unordered_set<int> numbers_set(default_set_ini);
//range constructor() creates set using range of values from [start, end) of another set
std::unordered_set<int> range_set(numbers_set.begin(), numbers_set.end());
// = operator used to initialize set or assign set to contents of another set
default_set = {0, 5, 6, 2};
default_set = numbers_set;

//capacity
//empty() return bool is set is empty
//size() returns number of elements in set
//max_size() returns max number of elements set can hold

//iterators
//begin() returns iterator to beginning of set
//end() returns iterator to end + 1 of set

//element lookup
//find() returns iterator to element if found in set or iterator to end
std::unordered_set<int>::iterator find_iterator = numbers_set.find(1);
if(find_iterator == numbers_set.end())
   std::cout<<"element not in set"<<'\n';
else 
   std::cout<< *find_iterator<<" is in the set"<<'\n';

//count() returns number of elements with given value. Since set has no duplicates it returns 1 if found or 0
for(auto& item: {0, 2, 1, 4})
   if(numbers_set.count(item) > 0)
      std::cout<<"Set contains: "<<item<<'\n';
   else
      std::cout<<"Set doesn't have: "<<item<<'\n';

//modifiers
//insert() can insert single, multiple or range of values from another 
int number9 = 9;
numbers_set.insert(number9);
numbers_set.insert(7);
numbers_set.insert({0, 5});
std::unordered_set<int> new_set = {55, 66, 77, 88, 99};
numbers_set.insert(new_set.begin(), new_set.end());

//erase() by key, iterator or range
find_iterator = numbers_set.find(99);
numbers_set.erase(77);
numbers_set.erase(find_iterator);

//clear() deletes all elements and sets size to 0
//swap() swaps contents of two sets
numbers_set.swap(default_set);
for(std::unordered_set<int>::iterator it = numbers_set.begin(); it != numbers_set.end(); ++it)
    std::cout<<*it<<' ';
std::cout<<'\n';
for(auto item: numbers_set)
      std::cout<<item<<' ';
std::cout<<'\n';
    return 0;
}