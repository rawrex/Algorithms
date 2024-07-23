#include <vector>
#include <limits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
	vector<int> luckyNumbers(vector<vector<int>>& input)
	{
		return naive(input);
	}

private:
	vector<int> naive(const vector<vector<int>>& input) const
	{
		using index_t = vector<int>::size_type;

		vector<int> result;
		unordered_map<index_t, int> row_tracker;
		unordered_map<index_t, int> col_tracker;

		for (index_t row_i = 0; row_i != input.size(); ++row_i)
		{
			int row_min = std::numeric_limits<int>::max();

			for (index_t col_i = 0; col_i != input[0].size(); ++col_i)
				row_min = std::min(input[row_i][col_i], row_min);

			row_tracker[row_i] = row_min;
		}

		for (index_t col_i = 0; col_i != input[0].size(); ++col_i)
		{
			int col_max = std::numeric_limits<int>::min();

			for (index_t row_i = 0; row_i != input.size(); ++row_i)
				col_max = std::max(input[row_i][col_i], col_max);

			col_tracker[col_i] = col_max;
		}

		for (index_t row_i = 0; row_i != input.size(); ++row_i)
		{
			for (index_t col_i = 0; col_i != input[0].size(); ++col_i)
			{
				if (row_tracker[row_i] == col_tracker[col_i])
				{
					result.emplace_back(input[row_i][col_i]);
					break;
				}
			}
		}

		return result;
	}
};

int main()
{

}