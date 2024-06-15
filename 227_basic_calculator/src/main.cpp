#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <functional>

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
        int result = 0;
        vector<string> muls_divs;
        vector<string> sum_dif_ops;

        // Simplify the management of the substrings by cutting the head of the string
        // This we will need to avoid later
        string tmp = input;

        auto index = tmp.find_first_of(m_sum_dif);
        while (index != std::string::npos)
        {
            // Collect the numbers and mul/div subexpressions first
            muls_divs.emplace_back(tmp.substr(0, index));
            // Collect the found sum/dif operators
            sum_dif_ops.emplace_back(tmp.substr(index, 1));

            // Truncate the just found sum/dif operator from the string
            tmp = tmp.substr(++index);

            // Try to find the next occurance of the sum/dif operator
            index = tmp.find_first_of(m_sum_dif);
        }

        // There is a number or a one or more mul/div subexpressions
        if (!tmp.empty())
            muls_divs.emplace_back(tmp);

        auto numbers = processMulsDivs(muls_divs);
        
        for (size_t i = 0; i != sum_dif_ops.size(); ++i)
        {
            const auto& current_operation_str = sum_dif_ops[i];
            const auto& lhs = numbers[i];
            const auto& rhs = numbers[i+1];
    
            auto operation = makeOperation(current_operation_str);

            result += operation(lhs, rhs);
        }

        return result;
    }

    vector<int> processMulsDivs(const vector<string>& muls_divs) const
    {
        vector<int> result;
         
        return result;
    }

    std::function<int(int, int)> makeOperation(const std::string& operation_str) const
    {
        switch (operation_str[0])
        {
            case '+':
                return m_operators[0];
            case '-':
                return m_operators[1];
            case '*':
                return m_operators[2];
            case '/':
                return m_operators[3];
			default:
                throw(std::logic_error("Wrong operation string"));
        }
    }

private:
    std::string m_mul_div = "*/";
    std::string m_sum_dif = "+-";

    std::array<std::function<int(int, int)>, 4> m_operators;
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
