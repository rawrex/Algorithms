#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Solution
{
    bool areSentencesSimilar(string s1, string s2) const
    {
        if (s1 == s2)
            return true;

        auto words1 = split(s1);
        auto words2 = split(s2);

        int size1 = words1.size();
        int size2 = words2.size();

        if (size1 > size2)
        {
            std::swap(words1, words2);
            std::swap(size1, size2);
        }

        int index = 0;

		for (; index < size1; ++index)
			if (words1[index] != words2[index])
				break;
 
        // The main trick, counts out the difference in sizes (the middle part) 
        // And checks to see that the tail of words2 is the same as the remaining part of words1
        for (; index < size1; ++index)
            if (words1[index] != words2[index + size2 - size1])
                break;

        return index == size1;
    }

    std::vector<std::string> split(const std::string& str) const
    {
        std::vector<std::string> words;
        std::string word;
        std::stringstream stream(str);

        while (std::getline(stream, word, ' '))
			words.emplace_back(word);

        return words;
    }
};

int main()
{
    Solution().areSentencesSimilar("A A", "A aA");
}
