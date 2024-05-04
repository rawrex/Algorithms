#include <iostream>
#include <vector>

template <typename Element_t>
void print(const std::vector<Element_t>& vec) noexcept
{
	for(const auto& i : vec)
		std::cout << i << ", ";
	std::cout << std::endl;
}
