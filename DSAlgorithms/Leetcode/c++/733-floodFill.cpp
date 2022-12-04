#include <iostream>
#include <vector>>

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color);
void DFS(std::vector<std::vector<int>>& image, int sr, int sc, int color, int oldColor);
int main()
{
    return 0;
}

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color)
{
    if(image[sr][sc] != color)    
        DFS(image, sr, sc, color, image[sr][sc]);
    return image;
}

void DFS(std::vector<std::vector<int>>& image, int sr, int sc, int color, int oldColor)
{
    if(sr < 0  || sr >= image.size() || sc < 0 || sc >= image[0].size())
        return;
    if(oldColor != image[sr][sc])
        return;
    DFS(image, sr-1, sc, color, oldColor);
    DFS(image, sr+1, sc, color, oldColor);
    DFS(image, sr, sc-1, color, oldColor);
    DFS(image, sr, sc+1, color, oldColor);
}