#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

struct Solution
{
    int countServers(vector<vector<int>>& grid)
    {
        std::unordered_map<int, int> rows;
        std::unordered_map<int, int> cols;

        for (int row = 0; row < grid.size(); ++row)
        {
            for (int col = 0; col < grid.back().size(); ++col)
            {
                if (grid[row][col])
                {
                    ++rows[col];
                    ++cols[row];
                }
            }
        }
            
        int count = 0;
        for (int row = 0; row < grid.size(); ++row)
        {
            for (int col = 0; col < grid.back().size(); ++col)
            {
                if (grid[row][col])
                    count += rows[col] > 1 || cols[row] > 1;
            }
        }

        return count;
    }
};

int main()
{
    vector<vector<int>> test{ {1, 0}, {0, 1} };

    std::cout << Solution().countServers(test) << std::endl;
}