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

        if (old_rows * old_cols != new_rows * new_cols)
            return mat;

        vector<vector<int>> reshaped(new_rows, vector<int>(new_cols, -1));

        for (int index = 0; index != new_rows * new_cols; ++index)
        {
            int old_row_i = index / old_rows;
            int old_col_i = index % old_cols;

            int new_row_i = new_rows == 1 ? 0 : index / new_rows;
            int new_col_i = index % new_cols;

            reshaped[new_row_i][new_col_i] = mat[old_row_i][old_col_i];
        }

        return reshaped;
    }
};

int main()
{
    Solution().matrixReshape({ {1,2}, {3,4} }, 1, 4);
}