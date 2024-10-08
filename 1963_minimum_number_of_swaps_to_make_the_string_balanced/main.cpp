#include <string>

using namespace std;

struct Solution
{
	int minSwaps(string s)
	{
		int tracker = 0;
		for (char ch : s)
		{
			if (ch == '[')
				++tracker;
			else if(tracker)
				--tracker;
		}

		return (tracker + 1) / 2;
	}
};