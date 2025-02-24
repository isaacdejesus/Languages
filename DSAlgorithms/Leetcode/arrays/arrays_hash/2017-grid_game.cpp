class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
       int cols = grid[0].size();
       std::vector<long long int> prefix_row1 = {grid[0][0]};
       std::vector<long long int> prefix_row2 = {grid[1][0]};
       

       for(int i = 1; i < cols; i++)
       {
           long long pre1 = grid[0][i] + prefix_row1[i - 1];
           long long pre2 = grid[1][i] + prefix_row2[i - 1];
           prefix_row1.push_back(pre1);
           prefix_row2.push_back(pre2);
       }
        long long result = 999999999999;
        for(int i = 0; i < cols; i++)
        {
            long long top_chunk = prefix_row1[cols - 1] - prefix_row1[i];
            long long bottom_chunk;
            if(i > 0)
                bottom_chunk = prefix_row2[i -1];
            else 
                bottom_chunk = 0;

            long long second_bot_max = std::max(top_chunk, bottom_chunk);
            result = std::min(result, second_bot_max);
        }
        return result;
    }
};