#include <iostream>
#include <string>
#include <unordered_map>

const std::string foo = "loveleetcode";
const std::string bar = "aabb";

struct Solution
{
	int firstUniqChar(const std::string& input) noexcept
	{
		// return naive(input);
		return counter(input);
	}

private:
	int counter(const std::string& input) noexcept
	{
		for (const auto& ch : input)
			++m_tracker[ch];

		for (int i = 0; i != input.size(); ++i)
			if (m_tracker[input[i]] == 1)
				return i;

		return -1;
	}

private:
	std::unordered_map<char, std::string::size_type> m_tracker;
};

int main()
{
	std::cout << Solution().firstUniqChar(foo) << std::endl;
	std::cout << Solution().firstUniqChar(bar) << std::endl;
}
