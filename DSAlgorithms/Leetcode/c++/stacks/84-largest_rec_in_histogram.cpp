class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<std::vector<int>> a_stack;
        int max_area = 0;
        std::vector<int> top;
        std::vector<int> current_bar;
        for(int i = 0; i < heights.size(); i++)
        {
           int start = i;
           if(!a_stack.empty())
                top = a_stack.top();
           while(!a_stack.empty() && top[1] > heights[i]) 
           {
               top = a_stack.top();
               a_stack.pop();
               max_area = std::max(max_area, top[1] * (i - top[0]));
               start = top[0];
                if(!a_stack.empty())
                    top = a_stack.top();
           }
            current_bar.push_back(start);
            current_bar.push_back(heights[i]);
            a_stack.push(current_bar);
            current_bar.clear();
        }
        while(!a_stack.empty())
        {
            top = a_stack.top();
            a_stack.pop();
            int temp = top[1] * (heights.size() - top[0]);
            max_area = std::max(max_area, temp);
        }
        return max_area;
    }
};