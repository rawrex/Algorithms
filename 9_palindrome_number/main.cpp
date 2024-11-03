#include <cmath>
#include <string>

struct Solution
{
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        if (x == 0)
            return true;

        int digits_n = static_cast<int>(std::log10(x));
        for (int front = digits_n, back = 0; back <= front; --front, ++back)
        {
            int front_digit = (x / static_cast<int>(std::pow(10, front))) % 10;
            int back_digit = (x / static_cast<int>(std::pow(10, back))) % 10;

            if (front_digit != back_digit)
                return false;
        }
        return true;
    }
};

int main()
{

}