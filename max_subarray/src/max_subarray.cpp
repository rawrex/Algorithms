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

struct CrossingHalf
{
	iter_t iterator;
	int sum;
};

using result_t = const std::pair<Range, int>;

// We should refactor these two later
// One of the considerations is to use a generic iterator function
// Which will be called with a normal and with a reverse iterator
const CrossingHalf FindLeftCrossingSum(iter_t& low, iter_t& mid)
{
	// The iterator to the furtherst to the left satisfactory element
	auto max_i = mid;
	// A sentinel 
	auto result_sum = INT_MIN;
	auto current_sum = 0;

	for(auto& i = mid; i != low; --i)
	{
		current_sum += *i;
		if (current_sum > result_sum)
		{
			result_sum = current_sum;
			max_i = i;
		}
	}
	return CrossingHalf{max_i, result_sum};
}

const CrossingHalf FindRightCrossingSum(iter_t& mid, iter_t& high)
{
	// The iterator to the furtherst to the left satisfactory element
	auto max_i = mid;
	// A sentinel 
	auto result_sum = INT_MIN;
	auto current_sum = 0;

	for(auto& i = mid; i != high; ++i)
	{
		current_sum += *i;
		if (current_sum > result_sum)
		{
			result_sum = current_sum;
			max_i = i;
		}
	}
	return CrossingHalf{max_i, result_sum};
}

result_t FindMaxCrossingSubarray(container_t& container, iter_t& low, iter_t& mid, iter_t& high)
{
	auto left = FindLeftCrossingSum(low, mid);
	auto right = FindRightCrossingSum(++mid, high);
	return {Range(left.iterator, right.iterator), left.sum + right.sum};
	
}



int main() {

}
