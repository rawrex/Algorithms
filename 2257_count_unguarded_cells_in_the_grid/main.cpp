#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

struct Solution 
{
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
    {
        rows_n = m;
        cols_n = n;

        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (const auto& row_col : walls)
            grid[row_col[0]][row_col[1]] = wall;

        for (const auto& row_col : guards)
            grid[row_col[0]][row_col[1]] = guard;

        for (int row = 0; row != m; ++row)
        {
            for (int col = 0; col != n; ++col)
            {
                if(grid[row][col] == guard)
					process(row, col, grid);
            }
        }

        int sum_guarded = 0;
        for (int row = 0; row != m; ++row)
        {
            for (int col = 0; col != n; ++col)
                sum_guarded += grid[row][col] == guarded ? 1 : 0;
        }

        return m * n - guards.size() - walls.size() - sum_guarded;
    }

private:
    void process(int row, int col, vector<vector<int>>& grid)
    {
		// upwards
        for (int r = row - 1; r >= 0 && grid[r][col] != wall && grid[r][col] != guard; --r)
            grid[r][col] = guarded;

		// downwards
		for (int r = row + 1; r < rows_n && grid[r][col] != wall && grid[r][col] != guard; ++r)
            grid[r][col] = guarded;

		// to the left
		for (int c = col - 1; c >= 0 && grid[row][c] != wall && grid[row][c] != guard; --c)
            grid[row][c] = guarded;

		// sum guarded to the right
		for (int c = col + 1; c < cols_n && grid[row][c] != wall && grid[row][c] != guard; ++c)
            grid[row][c] = guarded;
    }

	const static constexpr int wall = 1;
	const static constexpr int guard = 2;
	const static constexpr int guarded = 3;

    int rows_n = 0;
    int cols_n = 0;
};

int main()
{

}