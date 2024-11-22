#include <vector>
#include <string>
#include <bitset>
#include <unordered_map>

using namespace std;

struct Solution
{
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix)
    {
        unordered_map<string, int> counters;
        int max_count = std::numeric_limits<int>::min();

        string str_number;
        string str_number_inverse;

        for (const auto& row : matrix)
        {
			for (int bit : row)
			{
				str_number.push_back(bit != 1 ? '1' : '0');
				str_number_inverse.push_back(bit == 1 ? '1' : '0');
			}

            const auto& counter = ++counters[str_number];
            const auto& counter_inverse = ++counters[str_number_inverse];

            max_count = std::max(max_count, std::max(counter, counter_inverse));

			str_number.clear();
			str_number_inverse.clear();
        }

        return max_count;
    }
};

int main()
{
	vector<vector<int>> matrix{ {0,0,0},{0,0,1},{1,1,0} };
    Solution().maxEqualRowsAfterFlips(matrix);
}