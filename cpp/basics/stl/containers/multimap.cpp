#include <iostream>
#include <map>
//same as map. orders elements but there can be multiples of the same value
int main ()
{
    std::multimap<char, int> default_multimap;
    default_multimap.insert(std::pair<char, int>('b', 9));
    default_multimap.insert(std::pair<char, int>('z', 7));
    default_multimap.insert(std::pair<char, int>('b', 2));
    default_multimap.insert(std::pair<char, int>('z', 0));

    std::multimap<char, int> range_multimap( default_multimap.begin(), default_multimap.end());
    for(std::multimap<char, int>::iterator it = default_multimap.begin(); it != default_multimap.end(); it++)
    {
        std::cout<<it->first;
        std::cout<<it->second<<'\n';
    }
    //contains similar functions to map.
    //no way to access with at or []
    //only way to insert elements is with insert()
    return 0;
}
