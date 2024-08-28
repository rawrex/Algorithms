#include <vector>
#include <iostream>

using namespace std;

struct Solution 
{
	using matrix_type = vector<vector<int>>;

    int countSubIslands(matrix_type& grid1, matrix_type& grid2) 
    {
        if (grid1.empty())
            return 0;

        m_grid1 = &grid1;
        m_grid2 = &grid2;
        m_rows_n = grid1.size();
        m_cols_n = grid1[0].size();

        int counter = 0;

        for (int row = 0; row != m_rows_n; ++row)
        {
            for (int col = 0; col != m_cols_n; ++col)
            {
				if(isIsland(*m_grid2, row, col) && dfs(row, col))
					++counter;
            }
        }

        return counter;
    }

private:
    bool dfs(int row, int col) 
    {
        bool is_subisland = isIsland(*m_grid1, row, col);
        if (!is_subisland)
            return false;

        markProcessed(*m_grid2, row, col);

        if(!(dfs(row - 1, col) && dfs(row + 1, col) && dfs(row, col - 1) && dfs(row, col + 1)))
            is_subisland = false;

        return is_subisland;
    }

    inline bool isIsland(const matrix_type& grid, int row, int col) const noexcept
    {
        if (row < 0 || row >= m_rows_n || col < 0 || col >= m_cols_n)
            return false;

        return grid[row][col];
    }

    void markProcessed(matrix_type& grid, int row, int col) noexcept
    {
        grid[row][col] = 0;
    }

    matrix_type* m_grid1;
    matrix_type* m_grid2;

    int m_rows_n = 0;
    int m_cols_n = 0;
};

int main()
{

}