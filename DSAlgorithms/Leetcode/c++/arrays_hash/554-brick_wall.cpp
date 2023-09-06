class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
       std::unordered_map<int, int> hash;
       hash[0] = 0;
       for(int row = 0; row < wall.size(); row++)
       {
           int current_index = 0;
           for(int col = 0; col < wall[row].size() - 1; col++)
           {
               current_index += wall[row][col];
               if(hash.count(current_index) > 0)
               {
                   hash[current_index]++;
               }
               else
                    hash[current_index] = 1;
           }

       }
       int max = 0;
       for(auto item: hash)
           max = std::max(max, item.second);
        return wall.size() - max;
    }
};
