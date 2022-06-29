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

	// Skip the number if it is negative
	// Insert the number in the main result container if it is nonnegative
	void populateMainResultNonnegative(const int& number)
	{
		if (number < 0) return;
		main_result.push_back(square(number));
	}

	// Iterate over the input container populating main result
	// While ignoring negative numbers
	void doPositive(const std::vector<int>& numbers)
	{
		for (const auto & element : numbers)
			populateMainResultNonnegative(element);
	}

	// Sorted insert of the passed argument into the main result container
	void insertInMainResult(const int & number)
	{

	}

	// Iterate over the input contaier until a non-negative number is seen
	// While computing squares of the negative numbers and inserting them properly
	void doNegative(const std::vector<int>& numbers)
	{
		for (const auto & number : numbers)
			insertInMainResult(square(number));
	}

public:

	// Main call to solve the problem
	std::vector<int> solve(const std::vector<int> & input_numbers)
	{
		doPositive(input_numbers);
		doNegative(input_numbers);
		return main_result;
	}
};

int main() {
	Solution s;

	print(main_data);
	print(s.solve(main_data));
}
