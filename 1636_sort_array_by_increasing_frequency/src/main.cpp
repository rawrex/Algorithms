#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

struct Solution
{
	vector<int> frequencySort(vector<int>& input)
	{
		// return naive(input);
		// return memory(input);
		return speed(input);
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

	// Memory oriented solution
	vector<int> memory(vector<int>& input)
	{
		// Remembering that the values are from the -100 to 100
		vector<int> frequencies(201, 0);

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

	// Runtime oriented solution
	struct Data
	{
		friend bool operator<(const Data& a, const Data& b) noexcept
		{
			return a.frequency == b.frequency ? a.number < b.number : a.frequency > b.frequency;
		}

		Data(int num, unsigned freq) noexcept : number(num), frequency(freq)
		{

		}

		int number;
		unsigned frequency;
	};

	vector<int> speed(vector<int>& nums) 
	{
		vector<int> result;
		result.reserve(100);

		unordered_map<int, unsigned> count;
		priority_queue<Data, vector<Data>> heap;

		for (const int num : nums)
			++count[num];

		for (const auto& [num, freq] : count)
			heap.emplace(num, freq);

		while (!heap.empty()) 
		{
			const auto [num, freq] = heap.top();
			heap.pop();

			for (int i = 0; i < freq; ++i)
				result.emplace_back(num);
		}

		return result;
	}
};

int main()
{

}
