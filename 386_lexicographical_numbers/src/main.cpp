#include <set>
#include <vector>
#include <string>

using namespace std;

struct Solution 
{
    vector<int> lexicalOrder(int n) 
    {
        // return naive(n);
        return second(n);
    }

private:
    vector<int> second(int n)
    {
        auto sorter = [](int a, int b) 
        {
            int a_position = 1;
            for (int i = a; i; i /= 10)
                a_position *= 10;

            int b_position = 1;
            for (int i = b; i; i /= 10)
                b_position *= 10;

            int a_digit = 0;
            int b_digit = 0;
            for (/* empty */; a_position && b_position; a_position /= 10, b_position /= 10)
            {
                a_digit = a / a_position;
                b_digit = b / b_position;

                if (a_digit == b_digit)
                    continue;
            }

            return a_digit < b_digit;
        };

        multiset<int, decltype(sorter)> sorted(sorter);

        for (int i = 1; i <= n; ++i)
            sorted.emplace(i);

        return { std::cbegin(sorted), std::cend(sorted) };
    }

    vector<int> naive(int n)
    {
        string a_str;
        string b_str;

        auto sorter = [&a_str, &b_str](int a, int b) 
        { 
            a_str = std::to_string(a);
            b_str = std::to_string(b);

            return a_str < b_str;
        };

        set<int, decltype(sorter)> sorted(sorter);

        for (int i = 1; i <= n; ++i)
            sorted.emplace(i);

        return { std::cbegin(sorted), std::cend(sorted) };
    }
};

int main()
{
    Solution().lexicalOrder(13);
}