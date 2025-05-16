#include <iostream>
#include <map>

//map is associative container between keys and values
//values are stored sorted in order by key. No duplicates
//because values are sorted by key map is slower than unordered_map

int main() 
{
    //constructors
    std::map<char, int> default_map;
    std::map<char, int> default_map_ini({{'a', 1}, {'b', 3}});
    std::map<char, int> copy_map(default_map_ini);
    std::map<char, int> range_map(default_map_ini.begin(), default_map_ini.end());
    //assignment operator =, used to set one map to another map or to ini map
    std::map<char, int> chars_map = {{'a', 4}};
    chars_map = default_map_ini;
    //iterators begin() and end()
    for(std::map<char, int>::iterator it = chars_map.begin(); it != chars_map.end(); ++it)
        std::cout<<it->first<<" => "<<it->second<<'\n';
    //capacity functions
    //empty() returns bool
    //size() returns number of key/value pairs in the map
    //max_size() returns max number of key/value pairs map can hold
    //[] used to add new key value pairs, chance value mapped to key and to retrieve value mapped to key
    chars_map['z'] = 9;
    std::cout<<chars_map['z']<<'\n';
    //when using [] to access key value pair, if key doesn't exist, it is added with value of 0 and 0 is returned
    //if value is string, new key is added and value maps to ""
    std::cout<<chars_map['x']<<'\n';
    for(std::map<char, int>::iterator it = chars_map.begin(); it != chars_map.end(); ++it)
        std::cout<<it->first<<" => "<<it->second<<'\n';

    //at() returns a reference to key/value is in map. Else throws out of range exception
    std::cout<<chars_map.at('z')<<'\n';
    std::cout<<chars_map.count('x')<<'\n';
    //insert() single key/value pair or  range from another set
    chars_map.insert({'i', 7});
    chars_map.insert(default_map_ini.begin(), default_map_ini.end());
    //erase() single key/valye by key, by iterator or by range
    chars_map.erase('i');
    //erase using iterator returned by find
    chars_map.erase(chars_map.find('x'));
    //clear() deletes key/values from map
    //count() return 1 if key in map or 0 if not found.
    std::cout<<chars_map.count('x');
    return 0;
}