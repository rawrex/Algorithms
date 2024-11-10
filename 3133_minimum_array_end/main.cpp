#include <bitset>
#include <string>

struct Solution 
{
    long long minEnd(int n, int x) 
    {
		return mine(n, x);
    }

private:
	long long mine(int n, int x)
	{
		long long answer = x;
		while(--n)
		{
			++answer;
			answer |= x;
		}

		return answer;
	}

	long long another(int n, int x) 
	{
		--n;
		long long ans = x;
		for (int i = 0; i < 31; ++i) 
		{
			if (x >> i & 1 ^ 1) 
			{
				ans |= (n & 1) << i;
				n >>= 1;
			}
		}
		ans |= (1LL * n) << 31;
		return ans;
	}
};

int main()
{
	Solution().minEnd(3, 4);
}