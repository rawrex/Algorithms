#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

struct Solution
{
	vector<int> frequencySort(vector<int>& input)
	{
		vector<int> result;
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
				result.reserve(result.size() + freq);
				std::move(std::begin(tmp), std::end(tmp), std::back_inserter(result));
			}
		}

		return result;
	}
};

int main()
{

}