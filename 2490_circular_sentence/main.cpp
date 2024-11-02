#include <string>

using namespace std;

struct Solution 
{
    bool isCircularSentence(std::string_view sentence) const noexcept
    {
        if (sentence[0] != sentence[sentence.size() - 1])
            return false;

        for(size_t i = 0; i != sentence.size(); ++i)
        {
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
				return false;
        }

        return true;
    }
};

int main()
{
    Solution().isCircularSentence("leetcode exercises sound delightful");
}