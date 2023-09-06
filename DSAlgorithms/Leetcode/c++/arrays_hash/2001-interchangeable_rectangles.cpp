#include <iostream>
#include <vector>
#include <unordered_map>

    long long interchangeableRectangles(std::vector<std::vector<int>>& rectangles) {
        std::unordered_map<long double, int> hash;    
        long double ratio = 0;
        long long result = 0;
        for(int i = 0; i < rectangles.size(); i++)
        {
            ratio = (long double) (rectangles[i][0])/ (long double) (rectangles[i][1]);
            if(hash.count(ratio) > 0)
                hash[ratio]++;
            else 
                hash[ratio] = 1;
        }
        for(auto item: hash)
        {
            result += (long long) (item.second) * (long long) (item.second - 1) / 2;
        }
        return result;
    }
