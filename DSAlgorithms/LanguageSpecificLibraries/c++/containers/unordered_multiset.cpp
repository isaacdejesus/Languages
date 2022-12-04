#include <iostream>
#include <unordered_set>
#include <string>
//unordered_multiset stores elements hashlike. Not in order/ not contigiously for fast access.
//unlike unordered_set it allows duplicates

int main()
{
    //constructor()
    //default contructor creates empty multiset
    std::unordered_multiset<int> default_multiset;
    //default constructor can also be ini at declaration time
    //because multiset allows for duplicates, resulting set will be [1, 1, 1, 2, 3, 4]
    std::unordered_multiset<int> default_multiset_ini({1, 1, 1, 2, 3, 4});
    //copy constructor creates copy of existing multiset
    std::unordered_multiset<int> copied_multiset(default_multiset_ini);
    //range constructor creates new multiset by taking range of elements from another multiset
    std::unordered_multiset<int> ranged_multiset(default_multiset_ini.begin(), default_multiset_ini.end());

    // = assign operator used to initialise multiset or to assign one set to another set
    std::unordered_multiset<int> numbers_multiset;
    numbers_multiset = {1, 2, 3, 4, 1, 3};
    numbers_multiset = default_multiset_ini;

    //capacity functions
    //empty() returns bool if multiset is empty
    //size() returns number of elements in multiset
    //max_size() return max number of elements multiset can hold

    //iterators
    //begin() and end()

    //element look up functions
    //find() returns iterator to element if found or end()
    std::unordered_multiset<std::string> fruits_multiset = {"Mango", "Peach", "Melon", "Pineapple", "Orange"};
    std::unordered_multiset<std::string>::iterator pineapple_iterator = fruits_multiset.find("Pineapple");
    if(pineapple_iterator != fruits_multiset.end())
        std::cout<<*pineapple_iterator<<" is in the multiset"<<'\n';
    //count() returns count of given element in multiset
    std::cout<<"Count of 1's is: "<<numbers_multiset.count(1)<<'\n';

    //modifier functions
    //insert() can insert single item, or range 
    int number_9 = 9;
    numbers_multiset.insert(number_9);
    numbers_multiset.insert(9);
    numbers_multiset.insert({0, 1, 2, 3});
    numbers_multiset.insert(default_multiset_ini.begin(), default_multiset_ini.end());
    //erase() by iterator, key or range
    std::unordered_multiset<int>::iterator it = numbers_multiset.find(9);
    numbers_multiset.erase(it);
    //using a key to erase deletes all occurences of value. Here we delete all 1s in the set
    numbers_multiset.erase(1);
    //clear() deletes all elements and sets size to 0
    //swap() swaps contents of two multisets
    for(auto item: numbers_multiset)
        std::cout<<item<<' ';
    std::cout<<'\n';
    return 0;
}
