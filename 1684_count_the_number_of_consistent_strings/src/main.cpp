#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

struct Solution 
{
    int countConsistentStrings(string allowed_str, const vector<string>& words) 
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