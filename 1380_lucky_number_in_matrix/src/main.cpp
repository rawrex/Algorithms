#include <vector>
#include <limits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
	using index_t = vector<int>::size_type;

public:
	vector<int> luckyNumbers(vector<vector<int>>& input)
	{
		return naive(input);
	}

private:
	vector<int> naive(const vector<vector<int>>& input)
	{
		index_t rows_n = input.size();
		index_t cols_n = input[0].size();

		// Prefill the trackers with sentinel values
		row_tracker.reserve(rows_n);
		for (index_t row_i = 0; row_i != rows_n; ++row_i)
			row_tracker[row_i] = std::numeric_limits<int>::max();

		col_tracker.reserve(cols_n);
		for (index_t col_i = 0; col_i != cols_n; ++col_i)
			col_tracker[col_i] = std::numeric_limits<int>::min();

		// Collect the extreme values for each axis
		for (index_t row_i = 0; row_i != rows_n; ++row_i)
		{
			for (index_t col_i = 0; col_i != cols_n; ++col_i)
			{
				row_tracker[row_i] = std::min(row_tracker[row_i], input[row_i][col_i]);
				col_tracker[col_i] = std::max(col_tracker[col_i], input[row_i][col_i]);
			}
		}

		// Collect the lucky numbers
		for (index_t row_i = 0; row_i != rows_n; ++row_i)
		{
			for (index_t col_i = 0; col_i != cols_n; ++col_i)
			{
				if (row_tracker[row_i] == col_tracker[col_i])
					result.emplace_back(input[row_i][col_i]);
			}
		}

		return result;
	}

private:
	vector<int> result;
	unordered_map<index_t, int> row_tracker;
	unordered_map<index_t, int> col_tracker;
};

int main()
{

}