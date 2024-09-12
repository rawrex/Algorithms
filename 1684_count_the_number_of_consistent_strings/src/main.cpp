#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Solution 
{
    int countConsistentStrings(const string& allowed_str, const vector<string>& words) 
    {
		// return naive(allowed_str, words);
		return oneline(allowed_str, words);
    }

private:
	int oneline(const string& allowed_str, const vector<string>& words)
	{
		return words.size() - std::count_if(std::begin(words), std::end(words), [&allowed_str](const string_view& word) { return word.find_first_not_of(allowed_str) != std::string::npos; });
	}

    int naive(string allowed_str, const vector<string>& words) 
	{
		unordered_set<char> allowed(std::begin(allowed_str), std::end(allowed_str));
		size_t counter_inconsistent = 0;

		for (const auto& word : words)
		{
			for (char ch : word)
			{
				if (!allowed.contains(ch))
				{
					++counter_inconsistent;
					break;
				}
			}
		}

		return words.size() - counter_inconsistent;
	}
};

int main()
{
    Solution().countConsistentStrings("fstqyienx", { "n","eeitfns","eqqqsfs","i","feniqis","lhoa","yqyitei","sqtn","kug","z","neqqis" });
}