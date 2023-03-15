#include <iostream>

constexpr int first_bad_version_number = 21;
const bool isBadVersion(const int & i) { return i >= first_bad_version_number; }

int binsearch(const int& n)
{
	auto beg = 1, end = n;
	auto middle = [&beg, &end]() { return beg+(end-beg)/2; };
	auto mid = middle();

	while (mid != end)
	{
		if (isBadVersion(mid)) 
			end = mid;
		else
			beg = mid + 1;	
		mid = middle();
	}
	return mid;
}

void bad_version_main()
{
	auto result = binsearch(33);
	std::cout << result << std::endl;
}
