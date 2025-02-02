class Solution {
public:
    int maxArea(vector<int>& height) {
       int max = 0;
       int left = 0;
       int right = height.size() - 1;
       while(left < right) 
       {
           int area = (right - left) * std::min(height[left], height[right]);
           max = std::max(max, area);
           if(height[left] < height[right])
                left++;
            else
                right--;

       }
       return max;
    }
};