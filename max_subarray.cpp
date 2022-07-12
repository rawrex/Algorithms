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

using result_t = const std::pair<Range, int>;


result_t FindMaxCrossingSubarray(container_t& container, iter_t& low, iter_t& mid, iter_t& high)
{
	auto sum = 0;
	
	
}



int main() {

}
