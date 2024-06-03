#include <iostream>
#include <bits/stdc++.h>
class sorted_sq
{
    public:
        static std::vector<int> make_sq(const std::vector<int>& arr)
        {
            int n = arr.size();
            std::vector<int> squares(n);
            int highest_sq_index = n - 1;
            int left = 0;
            int right = n - 1;
            while(left <= right)
            {
                int left_sq = arr[left] * arr[left];
                int right_sq = arr[right] * arr[right];
                if(left_sq > right_sq)
                {
                    squares[highest_sq_index--] = left_sq;
                    left++;
                }
                else
                {
                    squares[highest_sq_index--] = right_sq;
                    right--;
                }
            }
            return squares;
        }
};

int main(int argc, char* argv[])
{
    std::vector<int> result = sorted_sq::make_sq(std::vector<int>{-2, -1, 0, 2, 3});
    for(auto num : result)
        std::cout<< num << " ";
    std::cout<<'\n';
    result = sorted_sq::make_sq(std::vector<int>{-3, -1, 0, 1, 2});
    for(auto num : result)
        std::cout<< num << " ";
    std::cout<<'\n';
}
