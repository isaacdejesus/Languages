#include <iostream>
#include <bits/stdc++.h>
class triplet_smaller_sum
{
    public:
        static int search_triplets(std::vector<int> &arr, int target)
        {
            std::sort(arr.begin(), arr.end());
            int count = 0;
            for(int i = 0; i < arr.size() - 2; i++)
                count += search_pair(arr, target - arr[i], i);
            return count;
        }
    private: 
        static int search_pair(const std::vector<int> &arr, int target_sum, int first)
        {
            int count = 0;
            int left = first + 1;
            int right = arr.size() - 1;
            while(left < right)
            {
                if(arr[left] + arr[right] < target_sum)
                {
                    count+= right - left;
                    left++;
                }
                else
                    right--;
            }
            return count;
        }
};
int main(int argc, char *argv[])
{
    std::vector<int> vec = {-1, 0, 2, 3};
    std::cout<< triplet_smaller_sum::search_triplets(vec, 3) <<'\n';
    vec = {-1, 4, 2, 1, 3};
    std::cout<< triplet_smaller_sum::search_triplets(vec, 5) <<'\n';

}
