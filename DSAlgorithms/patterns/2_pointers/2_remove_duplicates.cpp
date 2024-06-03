#include <iostream>
#include <bits/stdc++.h>
class remove_duplicates 
{
    public: 
        static int remove(std::vector<int>& arr)
        {
            int next_non_duplicate = 1;
            for(int i = 1; i < arr.size(); i++)
            {
                if(arr[next_non_duplicate - 1] != arr[i])
                {
                    arr[next_non_duplicate] = arr[i];
                    next_non_duplicate++;
                }
            }
            return next_non_duplicate;
        }
};
int main(int argc, char* argv[])
{
    std::vector<int> arr = {2, 3, 3, 3, 6, 9 , 9};
    std::cout<<"Array new length: "<<remove_duplicates::remove(arr)<<'\n';
    arr = {2, 2, 2, 11};
    std::cout<<"Array new length: "<<remove_duplicates::remove(arr)<<'\n';
}
