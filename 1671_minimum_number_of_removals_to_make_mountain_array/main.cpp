#include <vector>

using namespace std;

struct Solution
{
    int minimumMountainRemovals(vector<int>& nums)
    {
        vector<int> increasing;
        vector<int> decreasing;

        for (int number : nums)
        {
            if (auto iter = std::lower_bound(std::begin(increasing), std::end(increasing), number); iter == std::cend(increasing))
                increasing.push_back(number);
            else
                *iter = number;

            if (auto iter = std::lower_bound(std::begin(decreasing), std::end(decreasing), number); iter == std::cend(decreasing))
                decreasing.push_back(number);
            else
                *iter = number;
        }

        return nums.size() - increasing.size() - decreasing.size() + 1;
    }
};

int main()
{

}