#include <string>

struct Solution 
{
    bool isPalindrome(int x) 
    {
        auto str = std::to_string(x);
        int i = 0;
        int j = str.size() - 1;

        for (; i <= j; ++i, --j)
            if (str[i] != str[j])
                return false;

        return true;
    }
};

int main()
{

}