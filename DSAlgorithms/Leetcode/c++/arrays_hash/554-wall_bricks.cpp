class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
       std::unordered_map<int, int> gap_count;
       int end_of_brick = 0;
       int max_end_count = 0;
       int rows = wall.size();
       int cols; 
       for(int i = 0; i < rows; i++)
       {
           end_of_brick = 0;
           cols = wall[i].size() - 1;
           for(int j = 0; j < cols; j++)
           {
               end_of_brick += wall[i][j];
               if(gap_count.find(end_of_brick)!= gap_count.end())
                    gap_count[end_of_brick]++;
               else
                    gap_count[end_of_brick]  = 1;
                max_end_count = max(max_end_count, gap_count[end_of_brick]);
           }
       }
       return rows - max_end_count;
    }
};