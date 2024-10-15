#include <vector>
#include <queue>

using namespace std;

struct Solution 
{
    long long maxKelements(vector<int>& nums, int k)
    {
        long long score = 0;
        std::priority_queue<int> max_heap{ std::begin(nums), std::end(nums) };

        while (k)
        {
            auto max = max_heap.top();
            max_heap.pop();
            score += max;
            max = ceil(max / 3.0);
            max_heap.push(max);
            --k;
        }

        return score;
    }
};