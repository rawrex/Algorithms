#include <vector>
#include <bitset>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

struct Solution 
{
	const static size_t bits_n = sizeof(int) * 8;

    bool canSortArray(vector<int>& nums) 
    {
        size_t segment_bits = 0;
        int prev_segment_max = std::numeric_limits<int>::min();
        int segment_min = std::numeric_limits<int>::max();
        int segment_max = std::numeric_limits<int>::min();

        for (int number : nums)
        {
            auto bits = std::bitset<bits_n>(number).count();

            if (bits != segment_bits)
            {
                if (segment_min < prev_segment_max)
                    return false;

                prev_segment_max = segment_max;
                segment_bits = bits;

                segment_min = number;
                segment_max = number;
            }
            else
            {
                segment_min = std::min(segment_min, number);
                segment_max = std::max(segment_max, number);
            }
        }
        return prev_segment_max <= segment_min;
    }
};

int main()
{

}