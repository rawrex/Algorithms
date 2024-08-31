#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Solution
{
	vector<int> sortJumbled(vector<int>& mapping, vector<int>& numbers)
	{
		return naive(mapping, numbers);
	}

private:
	vector<int> naive(vector<int>& mapping, vector<int>& numbers) const
	{
		auto transformer = [&mapping](int number)
		{
			int result = 0;

			if (!number)
				return mapping[number];

			// Go up the decimal places for the "result" and crop out the least-significant digits in the "number"
			for(int position = 1; number; position *= 10, number /= 10)
				result += position * mapping[number % 10];

			return result;
		};

		// Use stable sort to preserve the relative placements for the input
		std::stable_sort(std::begin(numbers), std::end(numbers), [&transformer](const auto a, const auto b)
		{
			return transformer(a) < transformer(b);
		});

		return numbers;
	}
};

int main()
{

}