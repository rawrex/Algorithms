#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Solution 
{
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        auto size = nums.size();
        unordered_map<int, int> tracker;

        long long current_sum = 0;

        for (size_t index = 0; index < k; ++index)
        {
            ++tracker[nums[index]];
            current_sum += nums[index];
        }

        long long max = tracker.size() == k ? current_sum : 0;

        for (size_t index = k; index < size; ++index)
        {
            ++tracker[nums[index]];
            current_sum += nums[index];

            --tracker[nums[index - k]];
			current_sum -= nums[index - k];

            if (tracker[nums[index - k]] == 0)
                tracker.erase(nums[index - k]);

            if (tracker.size() == k)
                max = std::max(max, current_sum);
        }

        return max;
    }
};

int main()
{
    vector<int> test{ 1,1,1,7,8,9 };
    Solution().maximumSubarraySum(test, 3);
}