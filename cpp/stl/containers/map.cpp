#include <iostream>
#include <map>
//ordered, no repeats

int main()
{
    //constructor
    std::map<char, int> default_map;
    default_map['a'] = 9;
    default_map['v'] = 4;
    default_map['d'] = 0;

    std::map<char, int> range_map(default_map.begin(), default_map.end());

    std::map<char, int> copy_map(default_map);
    for(std::map<char, int>::iterator it = default_map.begin(); it != default_map.end(); it++)
    {
        std::cout<<it->first;
        std::cout<<it->second<<'\n';
    }

    //empty(), size(), clear()
    //access elements [] and at, takes in key and returns mapped value
    std::cout<<"Element mapped to key 'v' is: "<<default_map['v']<<'\n';
    std::cout<<"Element mapped to key 'd' is: "<<default_map['d']<<'\n';
    //find(), takes key, returns it to location.
    //count, return 1 if element found and 0 if not
    //insert
    default_map.insert(std::pair<char, int>('z', 77));
    //ranged insert
    //default_map.insert(map.begin(), map.end());
    //erase, needs iterator pointing to location
    std::map<char, int>::iterator it = default_map.find('v');
    //delete single value being pointed to by it
    //default_map.erase(it);   
    //delete range
    default_map.erase(it, default_map.end());
    for(std::map<char, int>::iterator it = default_map.begin(); it != default_map.end(); it++)
    {
        std::cout<<it->first;
        std::cout<<it->second<<'\n';
    }

    return 0;
}
