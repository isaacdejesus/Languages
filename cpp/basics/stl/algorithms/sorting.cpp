#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    std::vector<int> a_vector = {9, 3, 4, 2, 8, 11, 0};
    sort(a_vector.begin(), a_vector.end());
    for(auto element : a_vector)
        std::cout<<element<<' ';
    std::cout<<'\n';
    return 0;
}
