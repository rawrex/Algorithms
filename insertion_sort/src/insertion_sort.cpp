#include <iostream>
#include <vector>

constexpr size_t N = 12;
//int array[N] = {5, 1, -6, 0, 7, 3, 10, -43, 6, 7, 53, 12};
//std::vector<int> list = {35, 21, 1, 54, 7, -12, 65, 3, 1, 0, 15};

void print(int (&arr)[N])
{
	for (size_t i = 0; i!=N; ++i)
		std::cout << arr[i] << ' ';
std::cout << std::endl;
}


void insertion_sort(int (&arr)[N])
{
	for (size_t j = 1; j != N; ++j)
	{
		auto key = arr[j];
		int i = j-1; 

		for(; i>=0 && key<arr[i]; --i)
			arr[i+1] = arr[i];

		// We done going down the subarray
		arr[i+1] = key;
	}
}

void insertion_sort(std::vector<int> & lt)
{
	for (auto beg = lt.begin(), end = lt.end(); beg != end; ++beg)
	{
		auto key = *beg;
		auto iter = beg-1;

		for (; iter != lt.begin() && key<*iter; --iter)
			*(iter+1)=*iter;
			
		*(iter+1) = key;
	}
}
