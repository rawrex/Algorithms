#include <vector>

using namespace std;

struct Solution
{
	vector<vector<int>> construct2DArray(const vector<int>& original, int rows_n, int cols_n) const
	{
		if(auto size = original.size(); size != (static_cast<decltype(original.size())>(rows_n) * cols_n))
			return {};

		auto result = vector<vector<int>>(rows_n, vector<int>(cols_n));

		for (int row_i = 0; row_i != rows_n; ++row_i)
		{
			for (int col_i = 0; col_i != cols_n; ++col_i)
				result[row_i][col_i] = original[row_i * cols_n + col_i];
		}

		return result;
	}
};

int main()
{

}
