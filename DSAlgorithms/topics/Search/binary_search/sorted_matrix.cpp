#include <iostream>
#include <vector>

std::vector<int> search(std::vector<std::vector<int>>, int);
std::vector<int> b_search(std::vector<std::vector<int>>, int , int, int, int);
int main()
{
    std::vector<std::vector<int>> sorted_matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<int> result = search(sorted_matrix, 9);
    for(auto element: result)
        std::cout<<element<<'\n';
    std::cout<<'\n';
    return 0;
}
std::vector<int> search(std::vector<std::vector<int>> matrix, int target)
{
    int rows  = matrix.size();
    int cols = matrix[0].size(); 
    if(rows == 1)
        return b_search(matrix, 0, 0, cols - 1, target);
    int row_start = 0;
    int row_end = rows - 1;
    int col_mid = cols / 2;
    while(row_start < (row_end - 1))
    {
        int mid = row_start + (row_end - row_start) / 2;
        if(matrix[mid][col_mid] == target)
            return {mid, col_mid};
        if(matrix[mid][col_mid] < target)
            row_start = mid;
        else
            row_end = mid;
    }
    if(matrix[row_start][col_mid] == target)
        return {row_start, col_mid};
    if(matrix[row_start + 1][col_mid] == target)
        return {row_start + 1, col_mid};
    if(target <= matrix[row_start][col_mid - 1])
        return b_search(matrix, row_start, 0, col_mid - 1, target);
    if(target >= matrix[row_start][col_mid + 1] && target <= matrix[row_start][ cols - 1])
        return b_search(matrix, row_start, col_mid + 1, cols - 1, target);
    if(target <= matrix[row_start + 1][col_mid - 1])
        return b_search(matrix, row_start + 1, 0, col_mid - 1, target);
    if(target >= matrix[row_start][col_mid - 1])
        return b_search(matrix, row_start + 1, col_mid + 1, cols - 1, target);
}
std::vector<int> b_search(std::vector<std::vector<int>> matrix, int row, int col_start, int col_end, int target)
{
   while(col_start <= col_end) 
   {
       int mid = col_start + (col_end - col_start) / 2;
       if(matrix[row][mid] == target)
           return {row, mid};
   if(matrix[row][mid] < target)
       col_start = mid + 1;
   else
       col_end = mid - 1;
   }
   return {-1, -1};
}
