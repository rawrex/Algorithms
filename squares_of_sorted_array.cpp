#include <iostream>
#include <vector>
#include <map>

const std::vector<int> main_data = {-9, -6, -3, -1, -2, 0, 1, 3, 6, 9};

void print(const std::vector<int> & vec)
{
	for (const auto & i : vec)
		std::cout << i << ' ';
	std::cout << std::endl;
}

class Solution 
{
	// We can use the fact that we have a sorted input not only to populate result with nonnegative first
	// But also to speed up the later insertion of the negative ones

	// For clarity
	using input = int;
	using result = int;

	// Memoization container
	std::map<input, result> memory;

	// Store negative numbers to insert their squares at appropriate places later
	std::vector<int> negative_numbers;

	// Store non-negative numbers into the main container
	std::vector<int> main_result;

	inline int square(const int & number)
	{
		try
		{
			return memory.at(number);
		}
		catch (std::out_of_range& e)
		{
			auto tmp = number*number;
			memory[number] = tmp;
			return tmp;
		}
	}
	void doOnlyPositive(const std::vector<int>& numbers)
	{
		for (const auto & element : numbers)
			if (element < 0)
				negative_numbers.push_back(element);
			else 
				main_result.push_back(square(element));
	}
	void insertInMainResult(const int & number)
	{

	}
	void doNegative()
	{
		for (const auto & negnum : negative_numbers)
			insertInMainResult(square(negnum));
	}

public:
	std::vector<int> solve(const std::vector<int> & input_numbers)
	{
		doOnlyPositive(input_numbers);
		doNegative();
		return main_result;
	}
};

int main() {
	Solution s;

	print(main_data);
	print(s.solve(main_data));
}
