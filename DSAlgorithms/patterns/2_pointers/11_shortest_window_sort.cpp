#include<bits/stdc++.h>
class shortest_window_sort {
    public:
        static int sort(const std::vector<int>& arr)
        {
            int low = 0, high = arr.size() - 1;
            while(low < arr.size() - 1 && arr[low] <= arr[low + 1])
                low++;
            if(low == arr.size() - 1)
                return 0;
            while(high > 0 && arr[high] >= arr[high - 1])
                high--;
            int subarr_max = std::numeric_limits<int>::min();
            int subarr_min = std::numeric_limits<int>::max();
            for(int k = low; k <= high; k++)
            {
                subarr_max = std::max(subarr_max, arr[k]);
                subarr_min = std::min(subarr_min, arr[k]);
            }
            while(low > 0 && arr[low - 1] > subarr_min)
                low--;
            while(high < arr.size() -1 && arr[high + 1] < subarr_max)
                high++;
            return high - low + 1;
        }
};

int main(int argc, char* argv[])
{
    std::cout<<shortest_window_sort::sort(std::vector<int>{1, 2, 5, 3, 7, 10, 9, 12})<<'\n';
    std::cout<<shortest_window_sort::sort(std::vector<int>{1, 3, 2, 0, -1, 7, 10})<<'\n';
    std::cout<<shortest_window_sort::sort(std::vector<int>{1, 2, 3})<<'\n';
    std::cout<<shortest_window_sort::sort(std::vector<int>{3, 2, 1})<<'\n';
}
