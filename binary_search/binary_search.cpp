#include <iostream>
#include <vector>

//const std::vector<int> data1 = {-18, -3, 0, 1, 2, 5, 11, 23, 53, 199, 1329};
const std::vector<int> data2 = {-1,0,3,5,9,12};


// We can return:
// 1. Index
// 2. An iterator to the element
// 3. Boolean as whether the element is present
// We can get the index and the fact of presence of the element using the iterator

// C++11
template <typename Container, typename Element>
typename Container::const_iterator binsearch(const Container &, const Element &);
template <typename Container, typename Element>
typename Container::size_type binsearch_index(const Container&, const Element&);


int main() {
	std::cout << binsearch_index(data2, 2) << std::endl;
}

template <typename Container, typename Element>
typename Container::const_iterator binsearch(const Container& cont, const Element& sought)
{
	auto beg = cont.cbegin(), end = cont.cend();
	auto middle = [&beg, &end](){ return beg + (end-beg)/2; };
	auto mid = middle();

	while (mid != end && *mid != sought)
	{
		if (sought < *mid)
			end = mid;
		else
			beg = mid + 1;	
		mid = middle();
	}
	if (mid == end) throw std::exception();
	return mid;
}
template <typename Container, typename Element>
typename Container::size_type binsearch_index(const Container& cont, const Element& sought)
{
	std::vector<int>::size_type i = 0;
	try
	{
		i = binsearch(cont, sought) - cont.begin();
	}
	catch (...)
	{
		i = -1;
	}
	return i;
}
