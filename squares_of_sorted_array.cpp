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
	// But also to speed up the later insertion of the negative ones, based on their absolute value 

	// For clarity reasons
	using input = int;
	using result = int;

	// Memoization container
	std::map<input, result> memory;

	// Store negative numbers to insert their squares at appropriate places later
	std::vector<int> negative_numbers;

	// Store non-negative numbers into the main container
	std::vector<int> main_result;

	// Memoized squaring of the number,
	// return the result from the map if the square of the number was already computed
	inline int square(const int & number)
	{
		try
		{
			return memory.at(number);
		}
		catch (std::out_of_range& e)
		{
			return memory[number] = number*number;
		}
	}

	// Insert the number in the main result container if it is nonnegative
	// Insert it in the negative numbers container otherwise
	void populateProperNumbersContainer(const int& number)
	{
		if (number < 0)
			negative_numbers.push_back(number);
		else 
			main_result.push_back(square(number));
	}

	// Iterate over the input container and distribute numbers accordingly
	// Note, we can just avoid negative numbers here (w/o the separate container for them)
	// And then, after we done with the non-negative ones, we can just reiterate over the main input
	// Until we see a zero.
	// TODO:
	// For now I will stick to a separate container for negative numbers, but will revise it later.
	void doPositive(const std::vector<int>& numbers)
	{
		for (const auto & element : numbers)
			populateProperNumbersContainer(element);
	}

	// Sorted insert of the passed argument into the main result container
	void insertInMainResult(const int & number)
	{

	}

	// Iterate over the negative numbers container
	// And properly populate the main result container with squares of the numbers
	void doNegative()
	{
		for (const auto & negnum : negative_numbers)
			insertInMainResult(square(negnum));
	}

public:

	// Main call to solve the problem
	std::vector<int> solve(const std::vector<int> & input_numbers)
	{
		doPositive(input_numbers);
		doNegative();
		return main_result;
	}
};

int main() {
	Solution s;

	print(main_data);
	print(s.solve(main_data));
}
