#include <array>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

struct Solution
{
    int countServers(vector<vector<int>>& grid)
    {
        std::array<int, 250> rows;
        std::array<int, 250> cols;

        for (int row = 0; row < grid.size(); ++row)
        {
            for (int col = 0; col < grid.back().size(); ++col)
            {
                if (grid[row][col])
                {
                    ++rows[row];
                    ++cols[col];
                }
            }
        }
            
        int count = 0;
        for (int row = 0; row < grid.size(); ++row)
        {
            for (int col = 0; col < grid.back().size(); ++col)
            {
                if (grid[row][col])
                    count += rows[row] > 1 || cols[col] > 1;
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