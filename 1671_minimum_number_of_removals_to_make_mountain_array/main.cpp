#include <vector>

using namespace std;

struct Solution
{
    int minimumMountainRemovals(std::vector<int>& nums)
    {
        auto n = static_cast<int>(nums.size());
        std::vector<int> increasing_lengths(n, 1);
        std::vector<int> decreasing_lengths(n, 1);

        // Build increasing subsequence lengths
        std::vector<int> increasing;
        for (int i = 0; i < n; ++i)
        {
            int number = nums[i];

            if (auto iter = std::lower_bound(std::begin(increasing), std::end(increasing), number); iter == std::end(increasing))
                increasing.push_back(number);
            else
                *iter = number;

            increasing_lengths[i] = static_cast<int>(increasing.size());
        }

        // Build decreasing subsequence lengths from right to left
        std::vector<int> decreasing;
        for (int i = n - 1; i >= 0; --i)
        {
            int number = nums[i];

            if (auto iter = std::lower_bound(std::begin(decreasing), std::end(decreasing), number); iter == std::end(decreasing))
                decreasing.push_back(number);
            else
                *iter = number;

            decreasing_lengths[i] = static_cast<int>(decreasing.size());
        }

        int max_mountain = 0;
        for (int i = 1; i < n - 1; ++i)
        {
			// Valid peak
            if (increasing_lengths[i] > 1 && decreasing_lengths[i] > 1)
                max_mountain = std::max(max_mountain, increasing_lengths[i] + decreasing_lengths[i] - 1);
        }

        return n - max_mountain;
    }
};

int main()
{

}