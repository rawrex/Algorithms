#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const string test_str = "3*4 - 4 / 2";

class Operator
{
public:

private:
    enum class Type { plus = 0, minus = 1, mult = 2, div = 3 };
    Type m_type;
};

class Parser
{
public:
    int parse(const string& input) const noexcept
    {
        vector<string> muls_divs;
        vector<string> sum_dif_ops;

        // Simplify the management of the substrings by cutting the head of the string
        // This we will need to avoid later
        string tmp = input;

        auto i = tmp.find_first_of(m_sum_dif);
        while (i != std::string::npos)
        {
            // Collect the numbers and mul/div subexpressions first
            muls_divs.emplace_back(tmp.substr(0, i));
            // Collect the found sum/dif operators
            sum_dif_ops.emplace_back(tmp.substr(i, 1));

            // Truncate the just found sum/dif operator from the string
            tmp = tmp.substr(++i);

            // Try to find the next occurance of the sum/dif operator
            i = tmp.find_first_of(m_sum_dif);
        }

        // There is a number or a one or more mul/div subexpressions
        if (!tmp.empty())
            muls_divs.emplace_back(tmp);

        return -1;
    }

private:
    std::string m_mul_div = "*/";
    std::string m_sum_dif = "+-";
};

class Solution
{
public:
    int calculate(const string& s)
    {
        return naive(s);
    }

private:
    int naive(const string& input) const noexcept 
    {
        Parser parser;
        return parser.parse(input);
    }
};

int main()
{
    std::cout << Solution().calculate(test_str) << std::endl;
}
