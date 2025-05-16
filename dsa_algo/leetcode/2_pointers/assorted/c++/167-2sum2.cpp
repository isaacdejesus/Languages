class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       int left = 0;
       int right = numbers.size() - 1;
       std::vector<int> result;
       while(left < right) 
       {
           int current_sum = numbers[left] + numbers[right];
           if(current_sum > target)
                right--;
            else if(current_sum < target)
                left++;
            else
            {
                result.push_back(left + 1);
                result.push_back(right + 1);
                return result;
            }
       }
       return result;
    }
};