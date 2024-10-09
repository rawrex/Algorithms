#include <utility>
#include <vector>

using namespace std;

struct Solution 
{
    vector<vector<int>> matrixReshape(const vector<vector<int>>& mat, int new_rows, int new_cols) 
    {
        if (mat.empty())
            return mat;

        auto old_rows = mat.size();
        auto old_cols = mat[0].size();

        auto total_old_items = old_rows * old_cols;
        auto total_new_items = new_rows * new_cols;

        if (total_new_items != total_old_items)
            return mat;

        vector<vector<int>> reshaped(new_rows, vector<int>(new_cols, -1));

        for (int item = 0; item != total_new_items; ++item)
        {
            auto [old_row, old_col] = makeRowCol(item, old_rows, old_cols);
            auto [new_row, new_col] = makeRowCol(item, new_rows, new_cols);

            reshaped[new_row][new_col] = mat[old_row][old_col];
        }

        return reshaped;
    }

private:
    std::pair<int, int> makeRowCol(int index, int rows, int cols) const
    {
		int row = index / cols;
		int col = index - (row * cols);

        return std::make_pair(row, col);
    }
};

int main()
{
    Solution().matrixReshape({ {1,2}, {3,4} }, 1, 4);
}