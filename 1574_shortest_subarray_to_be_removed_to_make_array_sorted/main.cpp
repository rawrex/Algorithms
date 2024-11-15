#include <vector>
#include <numeric>

using namespace std;

struct Solution 
{
	int findLengthOfShortestSubarray(vector<int>& input)
	{
		int last = input.size() - 1;
		int left = 0;
		int right = last;

		while (left < right && input[left] <= input[left + 1])
			++left;

		if (left == last)
			return 0;

		while (right > 0 && input[right - 1] <= input[right])
			--right;

		int n = std::min(last - left, right);

		// Connect the two parts
		for (int new_left = 0, new_right = right; new_left <= left && new_right <= last; )
		{
			if (input[new_left] > input[new_right])
				++new_right;
			else
			{
				n = std::min(n, new_right - new_left - 1);
				++new_left;
			}
		}
		return n;
	}
};

int main()
{
    vector<int> test = { 1, 2, 3, 10, 4, 2, 3, 5 };
    Solution().findLengthOfShortestSubarray(test);
}