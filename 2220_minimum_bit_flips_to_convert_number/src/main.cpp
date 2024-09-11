#include <bitset>

struct Solution 
{
    int minBitFlips(int start, int goal) 
    {
        constexpr auto size = sizeof(int) * 8;

        std::bitset<size> start_bits(start);
        std::bitset<size> goal_bits(goal);

        int counter = 0;
        for (int i = 0; i != size; ++i)
            if (start_bits[i] != goal_bits[i])
                ++counter;

        return counter;
    }
};

int main()
{

}