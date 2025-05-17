#include<bits/stdc++.h>
int max_consecutive_ones(std::vector<int>& v);

int main()
{
    std::vector<int> v = {1, 0, 1, 1, 0, 1};
    std::cout<<max_consecutive_ones(v);
    return 0;
}
int max_consecutive_ones(std::vector<int>& v)
{
    int max_count = 0;
    int current_count = 0;
    for(auto val: v)
    {
        if(val == 0)
        {
            max_count = std::max(max_count, current_count);
            current_count = 0;
        }
        else
            current_count++;
    }
    return std::max(max_count, current_count);
}
