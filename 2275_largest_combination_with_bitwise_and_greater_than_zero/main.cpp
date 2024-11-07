#include <vector>
#include <bitset>
#include <algorithm>
#include <numeric>

using namespace std;

struct Solution 
{
	struct Comparator
	{
		bool operator()(int number) const noexcept { return std::bitset<bits_max>(number).test(m_bit_to_test); }
		int m_bit_to_test = 0;
	};

    int largestCombination(vector<int>& candidates) 
    {
        int max_count = 0;
        for (int i = 0; i != bits_max; ++i)
        {
            comparator.m_bit_to_test = i;
            max_count = std::max(max_count, static_cast<int>(std::count_if(std::cbegin(candidates), std::cend(candidates), comparator)));
        }
        return max_count;
    }

	Comparator comparator;
	const static size_t bits_max = 24; // log2(pow(10, 7));
};

int main()
{

}