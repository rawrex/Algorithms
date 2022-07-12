#include <iostream>
#include <utility>
#include <climits>
#include <vector>



using container_t = const std::vector<int>;
using iter_t = std::vector<int>::const_iterator;


class Range
{
	std::pair<iter_t, iter_t> range;
public:
	const iter_t low() const { return range.first; }
	const iter_t high() const { return range.second; }

	Range(const iter_t& beg, const iter_t & end) : range(beg, end) {}
};

struct CrossingResult
{
	iter_t iterator;
	int sum;
}

using result_t = const std::pair<Range, int>;

result_t FindMaxCrossingSubarray(container_t& container, iter_t& low, iter_t& mid, iter_t& high)
{
	auto left_result = FindLeftCrossingSum(low, mid);
	auto right_result = FindRightCrossingSum(mid, high);
	return {left_result.
	
}

const std::pair<iter_t, int> FindLeftCrossingSum(iter_t& low, iter_t& mid)
{
	// The iterator to the furtherst to the left satisfactory element
	auto max_left_i = mid;
	// A sentinel 
	auto left_result_sum = INT_MIN;
	auto current_sum = 0;

	for(auto& i = mid; i != low; --i)
	{
		current_sum += *i;
		if (current_sum > left_result_sum)
		{
			left_result_sum = current_sum;
			max_left_i = i;
		}
	}
	return std::pair<iter_t, int>(max_left_i, current_sum);
}

// We should refactor these two later
const std::pair<iter_t, int> FindRightCrossingSum(iter_t& mid, iter_t& high)
{
	// The iterator to the furtherst to the left satisfactory element
	auto max_right_i = mid+1;
	// A sentinel 
	auto right_result_sum = INT_MIN;
	auto current_sum = 0;

	for(auto& i = mid; i != high; --i)
	{
		current_sum += *i;
		if (current_sum > right_result_sum)
		{
			right_result_sum = current_sum;
			max_right_i = i;
		}
	}
	return std::pair<iter_t, int>(max_right_i, current_sum);
}


int main() {

}
