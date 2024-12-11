#include <string>
#include <cmath>

using namespace std;

struct Solution 
{
    string nearestPalindromic(const string& number)
    {
        return naive(number);
    }

private:
    string naive(const string& number)
    {
        auto n = std::stoul(number);
        auto up = n + 1;
        auto down = n - 1;

        for (; !isPalindrome(up); ++up);
        for (; !isPalindrome(down); --down);

        auto up_distance = up - n;
        auto down_distance = n - down;

        if (up_distance < down_distance)
            return std::to_string(up);
        else
            return std::to_string(down);
    }

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