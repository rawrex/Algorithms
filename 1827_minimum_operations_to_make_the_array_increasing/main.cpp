#include <vector>

using namespace std;

struct Solution 
{
    int minOperations(vector<int>& nums) 
    {
        auto size = nums.size();
        if (size < 2)
            return 0;

        int count = 0;
        size_t prev_index = 0;
        size_t curr_index = 1;

        for (; curr_index != size; ++curr_index, ++prev_index)
        {
            auto& prev = nums[prev_index];
			auto& curr = nums[curr_index];

            if (prev >= curr)
            {
                auto difference = (prev - curr) + 1;
                curr += difference;

                count += difference;
            }
        }

        return count;
    }
};