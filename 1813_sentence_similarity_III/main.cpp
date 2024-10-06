#include <string>

using namespace std;

struct Solution
{
    bool areSentencesSimilar(string s1, string s2)
    {
        if (s1 == s2)
            return true;

        string common_prefix;
        string common_suffix;

        auto iter1 = s1.cbegin();
        auto iter2 = s2.cbegin();

        auto riter1 = s1.crend();
        auto riter2 = s2.crend();

        for (; iter1 != s1.cend() && iter2 != s2.cend() && *iter1 == *iter2; ++iter1, ++iter2)
            common_prefix.push_back(*iter1);

        for (; riter1 != s1.crend() && riter2 != s2.crend() && *riter1 == *riter2; ++riter1, ++riter2)
            common_suffix.push_back(*riter1);

        return common_prefix == s1 || common_prefix == s2 || common_suffix == s1 || common_suffix == s2 || common_prefix + common_suffix == s1 || common_prefix + common_suffix == s2;
    }
};

int main()
{

}
