#include <string>

struct Solution 
{
    bool isPalindrome(int x) 
    {
        auto str = std::to_string(x);

        for (int i = 0, int j = str.size() - 1; i <= j; ++i, --j)
            if (str[i] != str[j])
                return false;

        return true;
    }
};

int main()
{

}