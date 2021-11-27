#include <iostream>
#include <set>

int main()
{
    //sets are a collection of unique numbers
    int arr [] = { 1, 2, 2, 3, 4, 5, 5};
    //std::set<int> a_set;
    //creates a set by copying elements from array using range
    std::set<int> a_set (arr, arr + 7);
    //empty(), clear()  and size()
    //only way to access elements is via iterator
    for(std::set<int>::iterator it=a_set.begin(); it!=a_set.end(); it++)
       std::cout<<' '<<*it;
    std::cout<<'\n';

    std::set<int> another_set;
    std::set<int>::iterator another_it;
    for(int i = 0; i < 5; i++)
        another_set.insert(i);

    //erase can work on a single element or a range
    another_it = another_set.find(3);
    another_set.erase(another_it);
    //delete from element 2 to end
    another_set.erase(another_set.find(2), another_set.end());
    for(another_it=another_set.begin(); another_it!=another_set.end(); another_it++)
        std::cout<<*another_it<<' ';
    std::cout<<'\n';
    //count returns 1 if element is in the set
    if(another_set.count(1))
        std::cout<<"element found in set"<<'\n';   

     
    return 0;
}
