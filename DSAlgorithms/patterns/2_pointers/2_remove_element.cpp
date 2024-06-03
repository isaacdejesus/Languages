#include <iostream>
#include <bits/stdc++.h>
class remove_element 
{
    public: 
        static int remove(std::vector<int>& arr, int key)
        {
            int next_element = 0;
            for(int i = 0; i < arr.size(); i++)
            {
                if(arr[i] != key)
                {
                    arr[next_element] = arr[i];
                    next_element++;
                }
            }
            return next_element;
        }
};
int main(int argc, char* argv[])
{
    std::vector<int> arr = {3, 2, 3, 6, 3, 10, 9, 3};
    std::cout<<"Array new length: "<<remove_element::remove(arr, 3)<<'\n';
    arr = {2, 11, 2, 2, 1};
    std::cout<<"Array new length: "<<remove_element::remove(arr, 2)<<'\n';
}
