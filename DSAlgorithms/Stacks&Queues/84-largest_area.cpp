#include<iostream>
#include<stack>
#include<vector>

int largest_rectangle_area(std::vector<int>);
int get_max(std::vector<int>&, std::stack<int>&, int, int);
int main()
{

    return 0;
}
int largest_rectangle_area(std::vector<int> heights)
{
    std::stack<int> st;
    int max = 0;
    stack.push(0);
    for(int i = 1; i < heights.size(); i++)
    {
        while(!st.empty() && heights[i] < heights[st.top()])
        {
            max = get_max(heights, st, max, i);
        }
        st.push(i);
    }
    int i = heights.size();
    while(!st.empty())
    {
        max = get_max(heights,st, max, i);
    }
    return max;
}
int get_max(std::vector<int>& arr, std::stack<int>& st, int max, int i)
{
    int area;
    int popped = st.top();
    st.pop();
    if(st.empty())
        area = arr[popped] * i;
    else 
        area = arr[popped] * (i - 1 - st.top());
    return std::max(max, area);
}