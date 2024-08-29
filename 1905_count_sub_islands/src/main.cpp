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
                if ((*m_grid2)[row][col] && dfs(row, col))
                    ++counter;
            }
        }

        return counter;
    }

private:
    bool dfs(int row, int col)
    {
        bool is_subisland = (*m_grid1)[row][col];

        // May return already
        if(!is_subisland)
            return false;

        // Marks as processed
        (*m_grid2)[row][col] = 0;

        auto row_up = row - 1;
        auto row_down = row + 1;
        auto col_left = col - 1;
        auto col_right = col + 1;

        // If the direction is valid and the grid2 has and island there, go further
        // And so for each direction...

		if (row_up >= 0 && (*m_grid2)[row_up][col] && !dfs(row_up, col))
			is_subisland = false;

		if (row_down < m_rows_n && (*m_grid2)[row_down][col] && !dfs(row_down, col))
			is_subisland = false;

		if (col_left >= 0 && (*m_grid2)[row][col_left] && !dfs(row, col_left))
			is_subisland = false;

		if (col_right < m_cols_n && (*m_grid2)[row][col_right] && !dfs(row, col_right))
			is_subisland = false;

        return is_subisland;
    }

    matrix_type* m_grid1 = nullptr;
    matrix_type* m_grid2 = nullptr;
    int m_rows_n = 0;
    int m_cols_n = 0;
};


int main()
{

}
