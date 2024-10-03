#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

struct Solution
{
    int minSubarray(std::vector<int>& nums, int p)
    {
        // Use long long to prevent overflow when summing up large numbers
        long long sum = std::accumulate(std::cbegin(nums), std::cend(nums), 0LL);
        int remainder = sum % p;

        if (remainder == 0)
            return 0;

        std::unordered_map<int, int> prefix_map;

        // For cases where the subarray starts from index 0
        prefix_map[0] = -1;

        long long current_prefix_sum = 0;
        int min_length = nums.size();

        for (int i = 0; i < nums.size(); ++i)
        {
            current_prefix_sum = (current_prefix_sum + nums[i]) % p;

            // We want to find a subarray whose sum is equivalent to remainder % p
            // Ensure the modulo result is positive
            int target = (current_prefix_sum - remainder + p) % p;

            if (prefix_map.contains(target))
                min_length = std::min(min_length, i - prefix_map[target]);

            // Record the current prefix sum % p and its index
            prefix_map[current_prefix_sum] = i;
        }

        return min_length == nums.size() ? -1 : min_length;
    }
};


int main()
{

}