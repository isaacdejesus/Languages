class Solution {
public:
    bool can_ship(int mid, int days, std::vector<int>& weights)
    {
        int ships = 1;
        int current_cap = mid;
        for(int i = 0; i < weights.size(); i++)
        {
            if((current_cap - weights[i]) < 0)
            {
                ships++;
                current_cap = mid;
            }
            current_cap -= weights[i];
        }
        return ships <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
       int left = 0;
       int right = 0; 
       for(int i = 0; i < weights.size(); i++)
       {
           left = std::max(left, weights[i]);
           right += weights[i];
       }
       int result = right; 
       while(left <= right)
       {
           int mid = left + (right - left) / 2;
           if(can_ship(mid, days, weights))
           {
               result = std::min(result, mid);
               right = mid - 1;
           }
           else
            left = mid + 1;
       }
       return result;
    }
};