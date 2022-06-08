#include <iostream>
#include <vector>

// Test container for merge()
std::vector<int> vec_merge = {4, 50, 60, 1, 3, 20};

// Main test container
std::vector<int> vec = {35, 21, 1, 54, 7, -12, 65, 3, 1, 0, 15};

using iter = std::vector<int>::iterator;

// Utility function to print a container
void print(const std::vector<int> & vec, const std::string& msg = "")
{
	if (!msg.empty())
		std::cout << msg << ' ';
	for (const auto & i : vec)
		std::cout << i << ' ';
	std::cout << std::endl;
}

// Subroutine that performs combination part of our Divide and Conquer algorithm
// We assume that the two subcontainers formed by iterator ranges [a;b] and [b+1;c] are in sorted order
void merge(std::vector<int>& vec, iter& a, iter& b, iter& c)
{
	// Make copies of the subarrays 
	std::vector<int> left(a, b+1), right(b+1, c);

	// Loop invariant:
	// At the start of each iteration of the loop
	// The subcontainer vec[a..i-1] contains the i-a smallest elements
	// of the left and right, in sorted order
	
	auto left_iter = left.begin();
	auto right_iter = right.begin();
	
	// We now basicly need to zip the two containers together

	auto exceed_left = [&left_iter, &left]() { return left_iter == left.end(); };
	auto exceed_right = [&right_iter, &right]() { return right_iter == right.end(); };
	auto exceeded = [&a, &c, &exceed_left, &exceed_right]
	{
		bool left_or_right = (exceed_left() || exceed_right());
		bool main = a == c; 
		return left_or_right || main;
	};

	for(/* empty */; !exceeded(); ++a)
		if (*left_iter <= *right_iter)
		{
			*a = *left_iter;
			++left_iter;
		}
		else
		{
			*a = *right_iter;
			++right_iter;
		}

	auto append_leftover = [&vec, &a](iter& beg, const iter& end)
	{
		for (/* empty */; beg != end; ++beg, ++a)
			*a = *beg;
	};
	if (exceed_left())
		append_leftover(right_iter, right.end());
	else if (exceed_right())
		append_leftover(left_iter, left.end());
	}
}

int main() 
{

	auto beg = vec_merge.begin(), half = vec_merge.begin()+2, end = vec_merge.end();
	print(vec_merge);
	merge(vec_merge, beg, half, end);
	print(vec_merge);

}
