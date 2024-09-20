#include <string>

struct Solution 
{
    bool isPalindrome(int x) 
    {
        auto str = std::to_string(x);
        
        int size = str.size();
        if (size == 1)
            return true;

        auto i = 0;
        auto j = size - 1;

        for (; i <= j; ++i, --j)
            if (str[i] != str[j])
                return false;

        return true;
    }
};

int main()
{

}