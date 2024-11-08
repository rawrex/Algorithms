#include <vector>
using namespace std;

struct Solution
{
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit)
    {
        vector<int> result;
        result.reserve(nums.size());

        int accumulated_xor = 0;
        for (auto number : nums)
            accumulated_xor ^= number;

        int k = (1 << maximumBit) - 1;

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            result.emplace_back(accumulated_xor ^ k);

            // Undo XOR for the latest element
            accumulated_xor ^= nums[i];
        }

        return result;
    }
};


int main()
{
    vector<int> test{ 0,1,1,3 };
    Solution().getMaximumXor(test, 2);
}