#include <vector>
#include <string>
#include <memory>
#include <unordered_set>

using namespace std;

struct Solution 
{
    int minExtraChar(const string& s, const vector<string>& dictionary)
    {
        // return naive(s, dictionary);
        return foo(s, dictionary);
    }

private:
    int naive(string s, const vector<string>& dictionary)
    {
        m_tracker = { cbegin(dictionary), cend(dictionary) };

        int beg = 0;
        int end = 0;
        while (check(s, beg, end))
        {
            s.erase(beg, end - beg + 1);
    
            // Reset indices after removal
            beg = 0;  
            end = 0;
        }

        return s.size();
    }

    bool check(const string& s, int& beg, int& end)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = i; j < s.size(); ++j)
            {
                auto substring = s.substr(i, j - i + 1);
                if (m_tracker.contains(substring))
                {
                    beg = i;
                    end = j;
                    return true;
                }
            }
        }

        return false;
    }

	int foo(const string& s, const vector<string>& dictionary) 
    {
        m_tracker = { std::cbegin(dictionary), std::cend(dictionary) };

		auto size = s.size();
		vector<int> dp(size + 1);

        // Base case: no extra character is needed for an empty substring.
		dp[0] = 0;

		// Calculate the minimum number of extra characters for each substring ending at position 'i'.
		for (int i = 1; i <= size; ++i) 
        {
			// Initialize dp[i] assuming all previous characters are from the dictionary and only s[i-1] is extra.
			dp[i] = dp[i - 1] + 1;

			// Check all possible previous positions 'j' to see if s[j, i-1] is a word in the dictionary.
			for (int j = 0; j < i; ++j) 
            {
				if (m_tracker.contains(s.substr(j, i - j))) 
                {
					// If it is a word, update dp[i] to be the minimum of its current value
					// and dp[j], which represents the minimum number of extra characters needed to form substring s[0...j-1].
					dp[i] = min(dp[i], dp[j]);
				}
			}
		}

		// This holds the minimum number of extra characters needed for the entire string.
		return dp[size];
	}

	unordered_set<string> m_tracker;
};

int main()
{
    Solution().minExtraChar("sayhelloworld", { "hello", "world" });
}