#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Solution 
{
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        int total_groups_count = nums.size();

        int total_elements_count = 0;
        for (const auto& group : nums)
            total_elements_count += group.size();

        // Create a vector to store the pair of values and their corresponding group index
        vector<pair<int, int>> sorted(total_elements_count);

        // Flatten all values along with their group index into sorted
        for (int i = 0, index = 0; i < total_groups_count; ++i) 
        {
            for (int value : nums[i]) 
                sorted[index++] = { value, i };
        }

        // Sort the elements based on values
        std::sort(std::begin(sorted), std::end(sorted));

        vector<int> result_range = { sorted[0].first, sorted.back().first };

        // Initialize pointers and a map to track the count of each group's presence in the current window
        int window_beg = 0;
        unordered_map<int, int> group_count;

        // Iterate through the sorted elements and find the minimum range that includes at least one number from each group.
        for (int window_end = 0; window_end < total_elements_count; ++window_end) 
        {
            const auto& [current_value, current_group] = sorted[window_end];

            // Add the current value to the count of its group.
            ++group_count[current_group];

            // Try to shrink the window from the left if all groups are present in the window.
            while (group_count.size() == total_groups_count) 
            {
                const auto& [window_beg_value, window_beg_group] = sorted[window_beg];

                // Compare with the current best range and update if necessary.
                int current_range = current_value - window_beg_value;
                int best_range = result_range[1] - result_range[0];

                if (current_range < best_range || (current_range == best_range && window_beg_value < result_range[0])) 
                {
                    result_range[0] = window_beg_value;
                    result_range[1] = current_value;
                }

                // Decrease the count of the starting group's element and possibly remove it from the hash map if count becomes zero
                if (--group_count[window_beg_group] == 0) 
                    group_count.erase(window_beg_group);

                ++window_beg;
            }
        }

        return result_range;
    }
};

int main()
{

}