#include <vector>
#include <string>

using namespace std;

struct Solution
{
    vector<string> summaryRanges(const vector<int>& nums)
    {
        vector<string> result;

        if (nums.empty())
            return result;

        int start = nums[0]; 
        for (int i = 1; i <= nums.size(); ++i)
        {
            if (i == nums.size() || nums[i] != nums[i - 1] + 1)
            {
                if (nums[i - 1] == start)
                    result.emplace_back(to_string(start));
                else
                    result.emplace_back(to_string(start) + "->" + to_string(nums[i - 1]));

                if (i != nums.size())
                    start = nums[i];
            }
        }

        return result;
    }
};


int main()
{
    Solution().summaryRanges({ 0,1,2,4,5,7 });
}