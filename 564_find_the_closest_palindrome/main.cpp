#include <cmath>
#include <string>
#include <unordered_set>

using namespace std;

struct Solution 
{
    string nearestPalindromic(const string& number)
    {
        input_n = stol(number);
        long closest = std::numeric_limits<long>::max();

        for (long candidate : getCandidates(number)) 
        {
            if (closest == -1)
                closest = candidate;
			else if (abs(candidate - input_n) < abs(closest - input_n) || (abs(candidate - input_n) == abs(closest - input_n) && candidate < closest))
                closest = candidate;
        }

        return to_string(closest);
    }

    unordered_set<long> getCandidates(const string& n) 
    {
        unordered_set<long> candidates;
        auto length = n.size();

        // the largest number with one less digit and the smallest number with one more digit
        candidates.emplace((long)pow(10, length - 1) - 1);
        candidates.emplace((long)pow(10, length) + 1);
        // Leads to different results
		// candidates.insert(static_cast<long>(pow(10, length - 1) - 1));
		// candidates.insert(static_cast<long>(pow(10, length) + 1));

        // Get the first half of the original number and consider the number one less, one greater, and itself
        long first_half = stol(n.substr(0, (length + 1) / 2));

        for (long i = first_half - 1; i <= first_half + 1; ++i) 
        {
			// First half as a string
            string prefix = to_string(i); 

            // Create a palindrome by appending the reverse of the prefix, considering odd/even length
            string candidate = prefix + string(prefix.rbegin() + (length & 1), prefix.rend());

            candidates.emplace(stol(candidate));
        }

        candidates.erase(input_n);
        return candidates;
    }

    long input_n = 0;
};

int main()
{
    Solution().nearestPalindromic("10000000000000000");
}