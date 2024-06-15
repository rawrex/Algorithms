#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <functional>

using namespace std;

const string test_str_1 = "3*4 - 4 / 2";
const string test_str_2 = "3+2*2";

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
        vector<string> sumdif_delimiters;
        vector<string> muls_divs = split(input, m_sum_dif, sumdif_delimiters);

        auto numbers = processMulsDivs(muls_divs);
        
        for (size_t i = 0; i != sumdif_delimiters.size(); ++i)
        {
            const auto& current_operation_str = sumdif_delimiters[i];
            const auto& lhs = numbers[i];
            const auto& rhs = numbers[i+1];
    
            auto operation = makeOperation(current_operation_str);

            result += operation(lhs, rhs);
        }

        return result;
    }

    vector<string> split(const string& input, const string& delimiters, vector<string>& found_delimiters) const
    {
        vector<string> result;

        // Simplify the management of the substrings by cutting the head of the string
        // This we will need to avoid later
        auto tmp = input;
        
        auto index = tmp.find_first_of(delimiters);
        while (index != std::string::npos)
        {
            // Collect the numbers and mul/div subexpressions first
            result.emplace_back(tmp.substr(0, index));

            // Collect the found sum/dif operators
            found_delimiters.emplace_back(tmp.substr(index, 1));

            // Truncate the just found sum/dif operator from the string
            tmp = tmp.substr(++index);

            // Try to find the next occurance of the sum/dif operator
            index = tmp.find_first_of(m_sum_dif);
        }

        // There is a number or a one or more mul/div subexpressions
        if (!tmp.empty())
            result.emplace_back(tmp);

        return result;
    }

    vector<int> processMulsDivs(const vector<string>& muls_divs) const
    {
        vector<int> result;

        for (const auto& expression : muls_divs)
        {
            vector<string> muldiv_delimiters;
            vector<string> numbers_str = split(expression, m_mul_div, muldiv_delimiters);

            for (size_t i = 0; i != muldiv_delimiters.size(); ++i)
            {
				const auto& current_operation_str = muldiv_delimiters[i];

                auto lhs = std::stoi(numbers_str[i]);
                auto rhs = std::stoi(numbers_str[i + 1]);
		
				auto operation = makeOperation(current_operation_str);

                result.emplace_back(operation(lhs, rhs));
            }
        }
         
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

    std::array<std::function<int(int, int)>, 4> m_operators = { std::plus<int>(), std::minus<int>(), std::multiplies<int>(), std::divides<int>() };
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
    std::cout << Solution().calculate(test_str_1) << std::endl;
    std::cout << Solution().calculate(test_str_2) << std::endl;
}
