#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct Solution
{
	vector<int> sortArray(vector<int>& input)
	{
		return mergeSort(input);
	}

private:
	vector<int> mergeSort(const vector<int>& input)
	{
		if (input.size() <= 1)
			return input;

		auto [L, R] = split(input);

		auto L_sorted = mergeSort(L);
		auto R_sorted = mergeSort(R);

		return merge(L_sorted, R_sorted);
	}

	pair<vector<int>, vector<int>> split(const vector<int>& input)
	{
		auto size = input.size();
		return
		{
			{ input.cbegin(), input.cbegin() + size/2 },
			{ input.cbegin() + size/2, input.cend() }
		};
	}

	vector<int> merge(const vector<int>& L, const vector<int>& R)
	{
		auto l_size = L.size();
		auto r_size = R.size();

		vector<int> result;
		result.reserve(l_size + r_size);

		size_t l_index = 0;
		size_t r_index = 0;

		// Merge the two
		while (l_index != l_size && r_index != r_size)
		{
			if (L[l_index] <= R[r_index])
			{
				result.emplace_back(L[l_index]);
				++l_index;
			}
			else
			{
				result.emplace_back(R[r_index]);
				++r_index;
			}
		}

		// Process remainings
		while (l_index != l_size)
		{
			result.emplace_back(L[l_index]);
			++l_index;
		}
		while (r_index != r_size)
		{
			result.emplace_back(R[r_index]);
			++r_index;
		}

		return result;
	}
};

int main()
{
	vector<int> a{ 5,2,3,1 };

	auto result = Solution().sortArray(a);

	std::cout << "Result: ";
	for (const auto i : result)
		std::cout << i << ' ';
	std::cout << std::endl;
}
