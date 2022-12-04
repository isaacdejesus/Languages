#include <iostream>
#include <unordered_map>

//unordered_multimap stores key/value pairs. Unordered, hash for fast retrievals.
//unlike unordered_map, unordered_multimap allows different elements to map to equivalent keys
//ex. a can map to 9 but can also have another a that maps to 4;
int main()
{
    //constructors
    //default constructor creates empty multimap
    std::unordered_multimap<char, int> default_multimap;
    //note we have to keys 'a'
    std::unordered_multimap<char, int> default_multimap_ini({{'a', 2}, {'b', 2}, {'a', 1}});
    //copy constructor
    std::unordered_multimap<char, int> copy_map(default_multimap_ini);
    //range constructor  
    std::unordered_multimap<char, int> range_map(default_multimap_ini.begin(), default_multimap_ini.end());

    //assignment operator =, used to ini map or assign one map to another map
    std::unordered_multimap<char, int> chars_map;
    chars_map = {{'a', 3}};
    chars_map = default_multimap_ini;

    //capacity functions
    //empty() returns bool is map is empty
    //size() returns number of key/value pairs in map
    //max_size() returns max possible amount of key/value pairs that can be stored in map

    //iterators
    //begin(), end()

    //element lookup functions
    //find() returns iterator to key if found or iterator to end()
    std::cout<<chars_map.find('a')->second<<'\n';
    //count() returns number of entries/keys in multimap with given key
    std::cout<<chars_map.count('a')<<'\n';

    //multimap modifiers
    //insert() can insert single key/value pair or range or pairs from existing multimap
    chars_map.insert({{'c', 5}});
    for(auto key: chars_map)
        std::cout<<key.first<<" : "<<key.second<<'\n';
    //erase() by key, interator or range
    std::unordered_multimap<char, int>::iterator it = chars_map.find('a');
    chars_map.erase(it);
    chars_map.erase('a');
    //clear() deletes all key/values from multimap
    //swap() swaps aky/values of two multimaps
    return 0;
}