#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Solution 
{
	long long countFairPairs(std::vector<int>& nums, int lower, int upper)
	{
		sort(begin(nums), end(nums));
		long long count = 0;
		size_t size = nums.size();

		// Iterate through each element as the "current" element
		for (size_t current_i = 0; current_i < size - 1; ++current_i)
		{
			size_t left_i = current_i + 1;
			size_t right_i = size - 1;

			// Find the smallest left
			while (left_i <= right_i)
			{
				if (auto mid_i = left_i + (right_i - left_i) / 2; nums[current_i] + nums[mid_i] >= lower)
					right_i = mid_i - 1;
				else
					left_i = mid_i + 1;
			}
			size_t valid_beg = left_i;

			left_i = current_i + 1;
			right_i = size - 1;

			// Find the largest right
			while (left_i <= right_i)
			{
				if (auto mid_i = left_i + (right_i - left_i) / 2; nums[current_i] + nums[mid_i] <= upper)
					left_i = mid_i + 1;
				else
					right_i = mid_i - 1;
			}
			size_t valid_end = right_i;

			if (valid_beg <= valid_end)
				count += (valid_end - valid_beg + 1);
		}

		return count;
	}
};