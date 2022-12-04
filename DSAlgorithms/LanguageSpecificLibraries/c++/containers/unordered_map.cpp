#include <iostream>
#include <unordered_map>
//unordered_map is associative container. Stores key to value pairs. 
//keys must be unique. No duplicates
//Values stored based on key hash value. Value retrieved using key
int main()
{
    //constructors
    //default creates empty unordered_map
    std::unordered_map<char, int> default_map;
    //can initialize map with constructor
    std::unordered_map<char, int> default_map_ini({{'x', 3}, {'y', 9}});
    //can also initialize map with assign = operator
    //char are key and int are value mapped to key
    std::unordered_map<char, int> map = {{'a', 2}, {'z', 1}};
    //copy constructor makes a copy of input map
    std::unordered_map<char, int> copy_multimap(map);
    //range constructor
    std::unordered_map<char, int> range_map(map.begin(), map.end());
    //assignment operator =, used to initialize or set one map to another map
    std::unordered_map<char, int> new_map;
    new_map = {{'a', 6}, {'b', 3}};
    default_map = map;

    //capacity functions
    //empty() returns bool is map is empty
    //size() returns total number of elements in map
    //max_size() returns max number of elements map can have

    //iterators
    //begin() and end()

    //access elements
    //[] can be used to add new key/value pairs and to access value by key
    //attempting to access non-existent key adds the key to map with value of 0 and return 0
    std::cout<<map['c'];
    std::cout<<map['a'];
    //adding new key/value
    map['c'] = 3;
    //changing value mapped to key
    std::cout<<map['c'];
    map['c'] = 6;
    std::cout<<map['c'];
    //if value is int, we can use ++ and -- and +=
    map['c']-=8;
    std::cout<<map['c'];
    //at() similar to [], except if key doesn't exist, return out of range exception
    std::cout<<map.at('c');
    std::cout<<'\n';
    //std::cout<<map.at('x');  //crashed due to out of range
    
    //element look up functions
    //find() returns iterator to key/value if found, else iterator to .end()
    std::unordered_map<char, int>:: iterator map_iterator = map.find('c');
    if(map_iterator != map.end()){
        std::cout<<map_iterator->first<<"  key found in map"<<'\n';
        std::cout<<"value is "<<map_iterator->second<<'\n';
    }
    //count() since there are no dulicates it return 1 is key in map and 0 is doesn't exist
    std::cout<<map.count('x');
    std::cout<<map.count('c');
    std::cout<<'\n';
    //insert() adds key/value to map. Only if key doesn't already exist on map
    map.insert({'x', 5});
    std::cout<<map['x'];
    std::cout<<'\n';
    //erase() can erase by iterator, key or range
    //iterator points to c
    map.erase(map_iterator);
    map.erase('x');
    for(auto key: map)
        std::cout<<key.first<<' '<<key.second<<'\n';

    //clear() deletes contents of map
    //swap() swaps elements between two maps
    return 0;
}