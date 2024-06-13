#include <iostream>
#include <string>
#include <unordered_set>
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
    int naive(const std::string& input) noexcept
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

	int counter(const std::string& input) noexcept
	{
		for (const auto& ch : input)
			++m_frequncies[ch];

		for (int i = 0; i != input.size(); ++i)
			if (m_frequncies[input[i]] == 1)
				return i;

		return -1;
	}

private:
	int counter(const std::string& input) noexcept
	{
		for (const auto& ch : input)
			++m_frequncies[ch];

		for (int i = 0; i != input.size(); ++i)
			if (m_frequncies[input[i]] == 1)
				return i;

		return -1;
	}

private:
	std::unordered_set<char> m_tracker;
	std::unordered_map<char, std::string::size_type> m_frequncies;
};

int main()
{
	std::cout << Solution().firstUniqChar(foo) << std::endl;
	std::cout << Solution().firstUniqChar(bar) << std::endl;
}
