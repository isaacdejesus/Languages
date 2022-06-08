#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
    std::vector<int> a_vector = {1, 2, 3, 4};
    std::reverse(a_vector.begin(), a_vector.end());
    for(auto element : a_vector)
        std::cout<<element;
    return 0;
}
