#include <iostream>
#include <string>
#include <unordered_set>

const std::string foo = "loveleetcode";
const std::string bar = "aabb";

struct Solution
{
	int firstUniqChar(const std::string& input) noexcept
	{
		for (int i = 0; i != input.size(); ++i)
		{
			if (!m_tracker.emplace(input[i]).second)
				continue;

			int j = i+1;

			for (; j != input.size(); ++j)
			{
				if (input[i] == input[j])
					break;
			}

			if (j == input.size())
				return i;
		}

		return -1;
	}

private:
	std::unordered_set<char> m_tracker;
};

int main()
{
	std::cout << Solution().firstUniqChar(foo) << std::endl;
	std::cout << Solution().firstUniqChar(bar) << std::endl;
}
