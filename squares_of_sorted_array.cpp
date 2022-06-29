#include <iostream>
#include <vector>
#include <cmath>
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
	using const_iter = std::vector<int>::const_iterator;

	// Memoization container
	std::map<input, result> memory;

	// Make a reference to the input container to avoid passing it via paramters too much
	const std::vector<int>& input_numbers;

	// Store non-negative numbers into the main container
	std::vector<int> main_result;

	// Memoized squaring of the absolute value of the number,
	// Return the result from the map if the square of the number was already computed
	inline int square(const int & number)
	{
		auto abs_number = std::abs(number);
		try
		{
			return memory.at(abs_number);
		}
		catch (std::out_of_range& e)
		{
			return memory[abs_number] = abs_number*abs_number;
		}
	}

	// Skip the number if it is negative
	// Insert the number in the main result container if it is nonnegative
	void addToMainResultNonnegative(const int& number)
	{
		if (number < 0) return;
		main_result.push_back(square(number));
	}

	// Iterate over the input container populating main result
	// While ignoring negative numbers
	void doPositive()
	{
		for (const auto & element : input_numbers)
			addToMainResultNonnegative(element);
	}

	// Sorted insert of the passed number into the main result container
	void sortedInsertNegative(const int & number)
	{
		
	}

	// Iterate over the input contaier until a non-negative number is seen
	// While computing squares of the negative numbers and inserting them properly
	void doNegative()
	{
		for (const auto & number : input_numbers)
		{
			if (number >= 0) return;
			sortedInsertNegative(square(number));
		}
	}

	// Utility binary search function
	inline const_iter binsearch(const int& target) const
	{
		auto beg = main_result.cbegin(), end = main_result.cend();
		auto middle = [&beg, &end](){ return beg + (end-beg)/2; };
		auto mid = middle();

		while (mid != end && *mid != target)
		{
			if (target < *mid)
				end = mid;
			else
				beg = mid + 1;	
			mid = middle();
		}
		return mid;
	}

public:
	
	// Constructor for our solver
	// Takes a reference to the input sequence and stores a reference to it
	Solution(const std::vector<int>& input) : input_numbers(input) {}

	// Main call to solve the problem
	std::vector<int> solve()
	{
		doPositive();
		doNegative();
		return main_result;
	}
};

int main() {
	print(main_data);
	Solution s(main_data);
	print(s.solve());
}
