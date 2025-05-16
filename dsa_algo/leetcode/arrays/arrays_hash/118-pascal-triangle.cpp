vector<vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> triangle;
    for(int i = 0; i < numRows; i++) 
    {
        std::vector<int> row(i + 1, 1);
        for(int j = 1; j < i; j++)
            row[j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
        triangle.push_back(row);
    }
    return triangle;
}
vector<vector<int>> pascal_triangle(int numRows) {
    std::vector<std::vector<int>> triangle;
    if(numRows == 0) 
        return triangle;
    std::vector<int> first_row;
    first_row.push_back(1);
    triangle.push_back(first_row);
    for(int i =1; i < numRows; i++)
    {
        std::vector<int> prev_row = triangle[i - 1];
        std::vector<int> current_row;
        current_row.push_back(1);
        for(int j = 1; j < i; j++)
            current_row.push_back(prev_row[j - 1] + prev_row[j]);
        current_row.push_back(1);
        triangle.push_back(current_row);
    }
    return triangle;
}
