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

        string word1;
        string word2;

        vector<string> words1;
        vector<string> words2;

        stringstream sswords1(s1);
        while (getline(sswords1, word1, ' '))
			words1.emplace_back(word1);

        stringstream sswords2(s2);
        while (getline(sswords2, word2, ' '))
			words2.emplace_back(word2);

        std::vector<string> common_prefix;
        std::vector<string> common_suffix;

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
        for(auto& word : common_suffix)
            std::reverse(std::begin(word), std::end(word));

        auto total = common_prefix;
        total.insert(std::end(total), std::begin(common_suffix), std::end(common_suffix));

        return common_prefix == words1 || common_prefix == words2 || common_suffix == words1 || common_suffix == words2 || total == words1 || total == words2;
    }
};

int main()
{
    Solution().areSentencesSimilar("A A", "A aA");
}
