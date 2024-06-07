#include <iostream>
#include <string>
#include <unordered_set>

struct Solution
{
	int firstUniqChar(const std::string& input) noexcept
	{
		// Go in reverse and remember the last unique character
		int last_unique = -1;

		for (int index = input.size(); index >= 0; --index)
		{
			char current_ch = input[index];
			// If we have not seen such character, remember it and update the current unique char
			if (m_tracker.emplace(current_ch).second)
				last_unique = index;
		}

		return last_unique;
	}

private:
	std::unordered_set<char> m_tracker;

};

int main()
{

}
