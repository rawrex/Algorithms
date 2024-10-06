#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Solution
{
    bool areSentencesSimilar(string s1, string s2)
    {
        if (s1 == s2)
            return true;

        std::vector<string> common_prefix;
        std::vector<string> common_suffix;

        auto iter1 = s1.cbegin();
        auto iter2 = s2.cbegin();

        auto riter1 = s1.crbegin();
        auto riter2 = s2.crbegin();

        string word1;
        string word2;
        stringstream ss1(s1);
        stringstream ss2(s2);

        while (getline(ss1, word1, ' ') && getline(ss2, word2, ' '))
        {
            if(word1 == word2)
                common_prefix.emplace_back(word1);
        }

        auto s1_reversed = s1;
        auto s2_reversed = s2;
        std::reverse(std::begin(s1_reversed), std::end(s1_reversed));
        std::reverse(std::begin(s2_reversed), std::end(s2_reversed));
        stringstream ss1_reversed(s1_reversed);
        stringstream ss2_reversed(s2_reversed);

        while (getline(ss1_reversed, word1, ' ') && getline(ss2_reversed, word2, ' '))
        {
            if(word1 == word2)
                common_suffix.emplace_back(word1);
        }

        // Transform the suffix so the characters are going left to right
        std::reverse(std::begin(common_suffix), std::end(common_suffix));

        auto total = common_prefix;
        total.insert(std::end(total), std::begin(common_suffix), std::end(common_suffix));

        return common_prefix == s1_set || common_prefix == s2_set || common_suffix == s1_set || common_suffix == s2_set || total == s1_set || total == s2_set;
    }
};

int main()
{
    Solution().areSentencesSimilar("My name is Haley", "My Haley");
}
