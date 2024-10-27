#include <vector>

using namespace std;

struct Solution 
{
    using matrix_t = vector<vector<int>>;

    int countSquares(const matrix_t& matrix)
    {
        auto additive_table = makeAdditiveTable(matrix);
        int count = 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int row = 0; row < matrix.size(); ++row)
        {
            for (int col = 0; col < matrix[0].size(); ++col)
            {
                auto submatrix_max_size = std::min(rows - row, cols - col);
                for (int k = 1; k <= submatrix_max_size; ++k)
                {
                    int bottom_row = row + k - 1;
                    int bottom_col = col + k - 1;

                    // Precomputed sum
                    int sum = additive_table[bottom_row][bottom_col];

                    if (row > 0) 
                        sum -= additive_table[row - 1][bottom_col];
                    if (col > 0) 
                        sum -= additive_table[bottom_row][col - 1];
                    if (row > 0 && col > 0)
                        sum += additive_table[row - 1][col - 1];

                    // If all elements are ones
                    if (sum == k * k)
                        ++count;
                }
            }
        }

        return count;
    }

private:
    matrix_t makeAdditiveTable(const matrix_t& matrix)
    {
        auto m = matrix;

        for (int row = 1; row < matrix.size(); ++row)
            m[row][0] += m[row - 1][0];

        for (int col = 1; col < matrix[0].size(); ++col)
            m[0][col] += m[0][col - 1];

		for (int row = 1; row < matrix.size(); ++row)
		{
			for (int col = 1; col < matrix[0].size(); ++col)
				m[row][col] = matrix[row][col] + m[row - 1][col] + m[row][col - 1] - m[row - 1][col - 1];
		}

        return m;
    }
};

int main()
{
    Solution().countSquares({ {1, 2}, {3, 4} });
}