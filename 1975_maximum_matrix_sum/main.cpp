#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Solution 
{
    long long maxMatrixSum(vector<vector<int>>& matrix) 
    {
        int min_absolute_value = std::numeric_limits<int>::max();
		int negative_count = 0;
        long long sum_absolute = 0;

        for (const auto& row : matrix)
        {
            for (int number : row)
            {
                if (number < 0)
                {
					number = std::abs(number);
					++negative_count;
                }

				sum_absolute += number;
                min_absolute_value = std::min(min_absolute_value, number);
            }
        }

        // If there are uneven number of negative numbers
        // We will use the smallest absolute value
        // By subtracting it from the sum, and its abs value, as it already has been added
        if (negative_count % 2)
            sum_absolute -= 2 * min_absolute_value;

        return sum_absolute;
    }
};

int main()
{

}