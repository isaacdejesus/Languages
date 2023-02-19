#include <iostream>
#include <vector>
int two_stacks(int, std::vector<int>, std::vector<int>);
int two_stacks_rec(int, std::vector<int>, std::vector<int>, int, int);
int main()
{
    std::vector<int> a = {4, 2, 4, 6, 1};
    std::vector<int> b = {2, 1, 8, 5};
    std::cout<<two_stacks(10, a, b);
    return 0;
}
int two_stacks(int x, std::vector<int> a, std::vector<int> b)
{
    return two_stacks_rec(x, a, b, 0, 0) - 1;
}
int two_stacks_rec(int x, std::vector<int> a, std::vector<int> b, int sum, int count)
{
    if(sum > x)
        return count;
    if(a.size() == 0 || b.size() == 0)
        return count;
    int current_a = a[0];
    int current_b = b[0]; 
    std::vector<int> a_ = a;
    std::vector<int> b_ = b;
    a_.erase(a_.begin());  //del first element
    b_.erase(b_.begin());  //delete first element
    int left = two_stacks_rec(x, a_, b, sum + current_a, count + 1);
    int right = two_stacks_rec(x, a, b_, sum + current_b, count + 1);
    //int left = two_stacks_rec(x, a.erase(a.begin()), sum + current_a, count + 1);
    //int right = two_stacks_rec(x, a, b.erase(b.begin()), sum + current_b, count + 1);
    return std::max(left, right);
}