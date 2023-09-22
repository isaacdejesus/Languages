class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0)
            return 0;
        int left = 0;
        int right = height.size() - 1;
        int left_max = height[left];
        int right_max = height[right];
        int sum = 0;
        while(left < right)
        {
            if(left_max < right_max)
            {
                left++;
                left_max = std::max(left_max, height[left]);
                sum += left_max - height[left];
            }
            else
            {
                right--;
                right_max = std::max(right_max, height[right]);
                sum += right_max - height[right];
            }
        }
        return sum;
    }
    
};