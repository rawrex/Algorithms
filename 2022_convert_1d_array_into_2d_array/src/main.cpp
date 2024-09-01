#include <vector>

using namespace std;

struct Solution
{
	vector<vector<int>> construct2DArray(const vector<int>& original, int rows_n, int cols_n) const
	{
		if (auto size = original.size(); size > (static_cast<decltype(original.size())>(rows_n) * cols_n))
			return {};

		auto result = vector<vector<int>>(rows_n, vector<int>(cols_n, 0));

		for (int i = 0; i != original.size(); ++i)
		{
			auto row_i = i / rows_n;
			auto col_i = i % cols_n;
			
			result[row_i][col_i] = original[i];
		}

		return result;
	}
};

int main()
{

}
