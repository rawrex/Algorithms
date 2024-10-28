#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

struct Solution 
{
    int longestSquareStreak(vector<int>& nums) 
    {
        // return ordered(nums);
        return unordered(nums);
    }

    int ordered(vector<int>& nums)
    {
        set<unsigned long long> sorted{ std::cbegin(nums), std::cend(nums) };

        int maximum = 0;
        int counter = 0;
        for (unsigned long long number : sorted)
        {
            for (unsigned long long square = number * number; sorted.contains(square); square = square * square)
                ++counter;

            maximum = std::max(maximum, counter);
            counter = 0;
        }

        return maximum ? maximum + 1 : -1;
    }

    int unordered(vector<int>& nums)
    {
        std::sort(std::begin(nums), std::end(nums));
        unordered_set<unsigned long long> tracker{ std::cbegin(nums), std::cend(nums) };

        int maximum = 0;
        int counter = 0;
        for (unsigned long long number : nums)
        {
            for (unsigned long long square = number * number; tracker.contains(square); square = square * square)
                ++counter;

            maximum = std::max(maximum, counter);
            counter = 0;
        }

        return maximum ? maximum + 1 : -1;
    }
};

int main()
{

}