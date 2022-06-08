#include <iostream>
#include <vector>

std::vector<int> vec = {35, 21, 1, 54, 7, -12, 65, 3, 1, 0, 15};
using iter = std::vector<int>::iterator;
void print(const std::vector<int> & vec)
{
	for (const auto & i : vec)
		std::cout << i << ' ';
	std::cout << std::endl;
}
void merge(std::vector<int>& vec, iter& a, iter& b, iter& c)
{
	// Make copies of the subarrays 
	std::vector<int> left(a, b), right(b+1, c);
	
	// Put sentinels (?)
	left.push_back(9999999);
	right.push_back(9999999);

	// Loop invariant:
	// At the start of each iteration of the loop
	// The subcontainer vec[a..i-1] contains the i-a smallest elements
	// of the left and right, in sorted order
	unsigned i = 0;
	unsigned j = 0;

	auto aa = a;

	for(; aa!=c; ++aa)
		if (left[i] <= right[j])
		{
			*aa = left[i];
			++i;
		}
		else
		{
			*aa = right[j];
			++j;
		}
}

int main() {

	auto beg = vec.begin(), half = vec.begin()+5, end = vec.end();
	print(vec);
	merge(vec, beg, half, end);
	print(vec);

}
