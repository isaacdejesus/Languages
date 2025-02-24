#include <iostream>
#include <vector>
int majorityElement(std::vector<int>& nums){
   int count = 0;
   int majorityElement = 0;
   for(int i = 0; i < nums.size(); i++)
   {
        if(count == 0)
            majorityElement = nums[i];
        if(majorityElement == nums[i])
            count++;
        else count--;
   }
   return majorityElement;
}
