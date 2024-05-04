#include <iostream>
#include <vector>
#include <map>
#include "../../utils/source/random.h"
#include "../../utils/source/print.h"

std::vector<int> countingSort(const std::vector<int>& input) noexcept
{
	std::vector<int> result;
	result.resize(input.size());

	std::map<int, size_t> frequency_tracker;

	for (int number : input)
		++frequency_tracker[number];

	size_t running_sum = 0;
	for (auto& [number, frequency] : frequency_tracker)
	{
		running_sum += frequency;
		frequency = running_sum;
	}

	for (int i = input.size() - 1; i >= 0; --i)
	{
		const auto& current_input_item = input[i];
		auto& frequency = frequency_tracker[current_input_item];

		result[frequency - 1] = current_input_item;
		--frequency;
	}

	return result;
}

int main()
{
	auto input = randomIntVector(10, 0, 3);
	print(input);

	auto result = countingSort(input);
	print(result);
}