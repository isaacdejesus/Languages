class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       std::unordered_map<int, int> count_hash;
       int left = 0;
       int total = 0;
       int result = 0;
       for(int right = 0; right < fruits.size(); right++) 
       {
           count_hash[fruits[right]]++;
           total++;
           while(count_hash.size() > 2)
           {
               int f = fruits[left];
               count_hash[f]--;
               total--;
               left++;
               if(count_hash[f] < 1)
                    count_hash.erase(f);
           }
           result = std::max(result, total);
       }
       return result;
    }
};