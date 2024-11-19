#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Solution 
{
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        auto size = nums.size();
        long long max = 0;
        unordered_set<int> tracker;

        for (size_t index = 0; index + k <= size; ++index)
        {
            tracker = { cbegin(nums) + index, cbegin(nums) + index + k };
            if (tracker.size() == k)
                max = std::max(max, std::accumulate(cbegin(tracker), cend(tracker), 0LL));
        }

        return max;
    }
};

int main()
{
    vector<int> test{ 1,1,1,7,8,9 };
    Solution().maximumSubarraySum(test, 3);
}