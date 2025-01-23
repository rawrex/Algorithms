#include <vector>
#include <bitset>
#include <algorithm>
#include <numeric>

using namespace std;

struct Solution 
{
    int largestCombination(vector<int>& candidates) 
    {
        int max_count = 0;
        for (int i = 0; i != bits_max; ++i)
        {
            int count = 0;
            for (const int candidate : candidates)
                if (candidate >> i & 1)
                    ++count;
            max_count = std::max(max_count, count);
        }
        return max_count;
    }

	const static size_t bits_max = 24; // log2(pow(10, 7));
};

int main()
{

}