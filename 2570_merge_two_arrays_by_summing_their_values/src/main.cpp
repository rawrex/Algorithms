#include <iostream>
#include <vector>

using namespace std;
using vvec_t = vector<vector<int>>;

const vvec_t foo = {{1, 2}, {2, 3}, {4, 5}};
const vvec_t bar = {{1, 4}, {3, 2}, {4, 1}};

class Solution
{
public:

	vvec_t mergeArrays(const vvec_t& a, const vvec_t& b) const noexcept
	{

		return {};
	}
};


int main()
{
	auto reulst = Solution().mergeArrays(foo, bar);
}