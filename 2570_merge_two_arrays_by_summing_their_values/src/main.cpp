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
		return naive(a, b);
	}

private:
	vvec_t naive(const vvec_t& a, const vvec_t& b) const noexcept
	{
		vvec_t result;

		auto size_a = a.size();
		auto size_b = b.size();

		size_t index_a = 0;
		size_t index_b = 0;

		while(index_a != size_a && index_b != size_b)
		{
			const auto& pair_a = a[index_a];
			const auto& pair_b = b[index_b];

			const auto& id_a = pair_a[0];
			const auto& id_b = pair_b[0];

			const auto& value_a = pair_a[1];
			const auto& value_b = pair_b[1];

			if (id_a == id_b)
			{
				result.emplace_back(std::vector<int>{id_a, value_a + value_b});

				++index_a;
				++index_b;

				continue;
			}
			else if (id_a < id_b)
			{
				result.emplace_back(std::vector<int>{id_a, value_a});

				++index_a;
				continue;
			}
			else
			{
				result.emplace_back(std::vector<int>{id_b, value_b});

				++index_b;
				continue;
			}
		}

		// Process the leftovers if any
		while (index_a != size_a)
		{
			result.emplace_back(a[index_a]);
			++index_a;
		}
		while (index_b != size_b)
		{
			result.emplace_back(b[index_b]);
			++index_b;
		}

		return result;
	}
};


int main()
{
	auto result = Solution().mergeArrays(foo, bar);

	for (const auto& vec : result)
		std::cout << vec[0] << ' ' << vec[1] << std::endl;
}