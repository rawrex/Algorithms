#include <vector>

using namespace std;

struct Solution
{
    int longestSubarray(vector<int>& nums) 
    {
        int max_value = std::numeric_limits<int>::min();
        for (int number : nums)
            max_value = std::max(max_value, number);

        int length = 0;
        int total_length = 0;
        for (int i = 0; i != nums.size(); ++i)
        {
            if (nums[i] == max_value)
                ++length;
            else 
                length = 0;

            total_length = std::max(total_length, length);
        }

        return total_length;
    }
};

int main()
{

}