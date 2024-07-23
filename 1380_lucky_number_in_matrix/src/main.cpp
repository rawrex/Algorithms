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

		unordered_map<index_t, int> row_tracker;
		unordered_map<index_t, int> col_tracker;

		for (index_t row_i = 0; row_i != input.size(); ++row_i)
		{
			for (index_t col_i = 0; col_i != input[row_i].size(); ++col_i)
			{
				int number = input[row_i][col_i];

				if (row_tracker.contains(row_i))
				{
					row_tracker[row_i] = std::min(row_tracker[row_i], number);
				}
				else
				{
					row_tracker[row_i] = number;
				}

				if (col_tracker.contains(col_i))
				{
					col_tracker[col_i] = std::max(col_tracker[col_i], number);
				}
				else
				{
					col_tracker[col_i] = number;
				}
			}
		}

		vector<int> result;
		for (const auto& [id, number] : row_tracker)
			result.emplace_back(number);

		return result;
	}
};

int main()
{

}