#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

struct Solution
{
	vector<int> frequencySort(vector<int>& input)
	{
		// return naive(input);
		return memory(input);
	}
private:
	vector<int> naive(vector<int>& input)
	{
		vector<int> result;
		result.reserve(100);
		unordered_map<int, unsigned> frequencies;
		map<unsigned, set<int, std::greater<int>>> sorted;

		for (int i : input)
			++frequencies[i];

		for (const auto& [number, freq] : frequencies)
			sorted[freq].emplace(number);

		for (const auto& [freq, numbers] : sorted)
		{
			for (int number : numbers)
			{
				auto tmp = std::vector(freq, number);
				std::move(std::begin(tmp), std::end(tmp), std::back_inserter(result));
			}
		}

		return result;
	}

	vector<int> memory(vector<int>& input)
	{
		// Remembering that the values are from the -100 to 100
		vector<int> frequencies(201, 0);
		map<unsigned, set<int, std::greater<int>>> sorted;

		for (int i : input)
			++frequencies[i + 100];	// value to improvised id correction, to avoid negative subscript

		sort(input.begin(), input.end(), [&frequencies](const int a, const int b) 
		{
			if (frequencies[a + 100] == frequencies[b + 100])
				return a > b;

			return frequencies[a + 100] < frequencies[b + 100];
		});

		return input;
	}
};

int main()
{

}