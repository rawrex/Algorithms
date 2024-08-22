#include <iostream>
#include <bitset>

void print(int number)
{
    auto n_bits = sizeof(int) * 8;
    for (int i = n_bits; i; --i)
    {
        if (!(i % 8))
            std::cout << ' ';

        if (number & (1 << i))
            std::cout << '1';
        else
            std::cout << '0';
    }
    std::cout << std::endl;
}


struct Solution
{
	int findComplement(int number)
	{
        std::bitset<sizeof(int) * 8> original(number);
        std::bitset<sizeof(int) * 8> complement(~number);

        auto i = sizeof(int) * 8 - 1;
        for (; i; --i)
            if (original[i]) break;
    
        for (auto j = i + 1; j != sizeof(int) * 8; ++j)
            complement.flip(j);
        
        return static_cast<int>(complement.to_ulong());
	}
};

int main()
{
	std::cout << Solution().findComplement(5) << std::endl;
}