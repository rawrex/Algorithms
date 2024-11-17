#include <vector>
#include <queue>
#include <numeric>

using namespace std;

struct Solution
{
    int shortestSubarray(vector<int>& nums, int k)
    {
        int size = nums.size();
        vector<long long> prefix_sums(size + 1, 0);

        for (int i = 1; i <= size; ++i)
            prefix_sums[i] = nums[i - 1] + prefix_sums[i - 1];

        int min_subarray = std::numeric_limits<int>::max();
        std::deque<int> dq;

        for (int i = 0; i <= size; ++i)
        {
            // Check for valid subarray from deque front
            while (!dq.empty() && prefix_sums[i] - prefix_sums[dq.front()] >= k)
            {
                min_subarray = std::min(min_subarray, i - dq.front());
                dq.pop_front();
            }

            // Maintain monotonicity of deque
            while (!dq.empty() && prefix_sums[i] <= prefix_sums[dq.back()])
                dq.pop_back();

            dq.push_back(i);
        }

        return min_subarray == std::numeric_limits<int>::max() ? -1 : min_subarray;
    }
};

int main()
{

}