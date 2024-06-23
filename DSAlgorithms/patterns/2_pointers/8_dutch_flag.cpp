#include <bits/stdc++.h>
class dutch_flag {
    public:
        static void sort(std::vector<int> &arr)
        {
            int low = 0;
            int high = arr.size() - 1;
            for(int i = 0; i <= high;)
            {
                if(arr[i] == 0)
                {
                    swap(arr, i, low);
                    i++;
                    low++;
                }
                else if(arr[i] == 1)
                    i++;
                else
                {
                    swap(arr, i, high);
                    high--;
                }
            }
        }
    private: 
        static void swap(std::vector<int> &arr, int i, int j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
};

int main(int argc, char *argv[])
{
    std::vector<int> arr = {1, 0, 2, 1, 0};
    dutch_flag::sort(arr);
    for(auto num : arr)
        std::cout<<num<<" ";
    std::cout<<'\n';

    arr = {2, 2, 0, 1, 2, 0};
    dutch_flag::sort(arr);
    for(auto num : arr)
        std::cout<<num<<" ";
    std::cout<<'\n';
}
