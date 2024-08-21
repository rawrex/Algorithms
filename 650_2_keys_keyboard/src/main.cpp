#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

struct Solution
{
	int minSteps(int n) const
	{
        if (n <= 1)
            return 0;

        vector<int> memoization;
        memoization.reserve(static_cast<vector<int>::size_type>(n) + 1);

        // Each element denotes the minimum steps to get the number of 'A's according to the element's index
        // For now, we fill it with the values of the approach where we copy 'A' and then paste 'A' index - 1 times
        iota(memoization.begin(), memoization.end(), 0);

        for (int i = 2; i <= n; ++i)
        {
            for (int j = i / 2; j > 2; --j)
            {
                if (i % j == 0) 
                {
                    memoization[i] = memoization[j] + i / j;  // Paste dp[j] i / j times.
                    break;
                }

            }
        }
        return memoization[n];
	}
};

struct Solution2
{
    int minSteps(int n) 
    {
        // Initialize the memoization table
        memo.assign(static_cast<vector<int>::size_type>(n) + 1, -1);

        return dfs(n);
    }

    int dfs(int n) 
    {
        if (n <= 1) 
            return 0;

        // Check the cache
        if (memo[n] != -1) 
            return memo[n];

        // Initialize the answer with the non-optimal value (copying 'A' once and then pasting it)
        int ans = n;

        // Searching for the factors of n
        for (int i = 2; i * i <= n; ++i) 
        {
            if (n % i)
                continue;

			// Recursively solve for the smaller problem 'n / i' and add 'i' steps 
			// (the steps to copy 'A' once and then paste it i-1 times to get the i number of 'A's)
			ans = min(ans, dfs(n / i) + i);
        }

        memo[n] = ans;
        return ans;
    }

    vector<int> memo;
};

int main()
{

}