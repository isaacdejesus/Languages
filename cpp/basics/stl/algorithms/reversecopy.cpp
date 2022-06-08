#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int arr [] = {1, 2, 3, 4, 5};
    std::vector<int> a_vector;
    a_vector.resize(5); //vector needs to resized to fit incoming elements
    std::reverse_copy(arr, arr + sizeof(arr)/sizeof(int), a_vector.begin());
    for(auto element : a_vector)
        std::cout<<element;
    std::cout<<'\n';
    std::vector<int> new_vector;
    new_vector.resize(5); //vectore must be resized to fit incoming elements
    std::reverse_copy(a_vector.begin(), a_vector.end(), new_vector.begin());
    for(auto element : new_vector)
        std::cout<<element;

    //copy works the same way
}
