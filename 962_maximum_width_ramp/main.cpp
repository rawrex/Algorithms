#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

struct Solution
{
	int maxWidthRamp(std::vector<int>& nums)
	{
		// Stack to store indices of decreasing elements
		std::vector<int> decreasing_indices;

		// Collect the indices of elements that form a decreasing sequence
		for (int i = 0; i < nums.size(); ++i)
		{
			if (decreasing_indices.empty() || nums[decreasing_indices.back()] > nums[i])
				decreasing_indices.push_back(i);
		}

		// Iterate from the end and find the maximum width ramp
		int max_width = 0;
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			while (!decreasing_indices.empty() && nums[decreasing_indices.back()] <= nums[i])
			{
				max_width = std::max(max_width, i - decreasing_indices.back());
				decreasing_indices.pop_back();
			}
		}

		return max_width;
	}
};


int main()
{

}