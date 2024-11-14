#include <vector>
#include <algorithm>

using namespace std;

struct Solution 
{
	int minimizedMaximum(int n, vector<int>& quantities)
	{
		int left = 1;
		int right = 1e5;

		while (left < right)
		{
			int count = 0;
			int mid = (left + right) >> 1;

			// Calculate and add number of shelves needed for each quantity
			for (int quantity : quantities)
				count += (quantity + mid - 1) / mid;

			// If the count is less, there might be a more efficient solution
			// Otherwise, search in the right side
			if (count <= n)
				right = mid;
			else
				left = mid + 1;
		}

		// When left meets right
		return left;
	}
};

int main()
{

}