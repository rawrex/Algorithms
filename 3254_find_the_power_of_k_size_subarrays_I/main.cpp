#include <vector>

using namespace std;

struct Solution 
{
    vector<int> resultsArray(vector<int>& nums, int k) 
    {
        auto size = nums.size();

        vector<int> result;
        result.reserve(size - k + 1);

        vector<int> tracker(size, -1);
        tracker[0] = 1;

        // Calculate the consequtive lengths
        for (int i = 1; i < size; ++i)
            tracker[i] = nums[i - 1] + 1 == nums[i] ? tracker[i - 1] + 1 : 1;

        // If the length for the current window is greater or equal to k,
        // then use the window's last element valus
        for (int i = k - 1; i < size; ++i)
            result.emplace_back(tracker[i] >= k ? nums[i] : -1);

        return result;
    }
};

int main()
{
    vector<int> test{ 1, 4 };
    Solution().resultsArray(test, 1);
}