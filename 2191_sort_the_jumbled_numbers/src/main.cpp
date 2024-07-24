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
			if (!number)
				return mapping[number];

			int result = 0;
			for(int position = 1; number; position *= 10)
			{
				int mapped_digit = mapping[number % 10];
				result = mapped_digit * position + result;

				number /= 10;
			}

			return result;
		};

		std::sort(numbers.begin(), numbers.end(), [&transformer](const auto a, const auto b)
		{
			return transformer(a) < transformer(b);
		});

		return numbers;
	}
};

int main()
{

}