#include<bits/stdc++.h>
class circular_arr_loop {
    public:
        static bool loop_exists(const std::vector<int> &arr)
        {
            for(int i = 0; i < arr.size(); i++)
            {
                bool is_forward = arr[i] >= 0;
                int slow = i;
                int fast = i;
                do{
                    slow = find_next_index(arr, is_forward, slow);
                    fast = find_next_index(arr, is_forward, fast);
                    if(fast != -1)
                        fast = find_next_index(arr, is_forward, fast);
                }
                while(slow != -1 && fast != -1 && slow != fast);
                if(slow != -1 && slow == fast)
                    return true;
            }
            return false;
        }
    private:
        static int find_next_index(const std::vector<int> &arr, bool is_forward, int current_index)
        {
            bool direction = arr[current_index] >= 0;
            if(is_forward != direction)
                return -1;
            int next_index = (current_index + arr[current_index] + arr.size()) % arr.size();
            if(next_index == current_index)
                next_index--;
            return next_index;
        }
};
int main(int argc, char *argv[])
{
    std::cout<<circular_arr_loop::loop_exists(std::vector<int>{1, 2, -1, 2, 2})<<'\n';
    std::cout<<circular_arr_loop::loop_exists(std::vector<int>{2, 2, -1, 2})<<'\n';
    std::cout<<circular_arr_loop::loop_exists(std::vector<int>{2, 2, -1, -2})<<'\n';
}
