#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Solution 
{
    int getLucky(const string& s, int k) const noexcept
    {
        int number = 0;

        for (char c : s)
            number += sumDigits(c - 'a' + 1);

        // One transformation was already done above (on the go transformation)
        for (int i = 0; i != k - 1; ++i)
            number = sumDigits(number);

        return number;
    }

private:
    int sumDigits(int number) const noexcept
    {
		int sum = 0;

		for (/* empty */; number; number /= 10)
            sum += number % 10;
		
        return sum;
    }
};

int main()
{
    Solution().getLucky("leetcode", 2);
}