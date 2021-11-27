#include <iostream>
#include <unordered_set>
//contains unique elements in no particular order
int main()
{
    std::unordered_set<int> a_set({8, 3, 2, 9});
    //empty(), size(), clear(), find(), count()
    std::unordered_set<int>::iterator it = a_set.find(3);
    std::cout<<*it<<'\n';
    //insert() erase() like in other stl containers


    return 0;
}
