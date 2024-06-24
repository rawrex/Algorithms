#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <stack>
#include <functional>

using namespace std;

const string test_str_1 = "3*4 - 4 / 2";
const string test_str_2 = "3+2*2";
const string test_str_3 = " 3/2 ";
const string test_str_4 = "1+1+1";
const string test_str_5 = "2*3*4";
const string test_str_6 = "1*2-3/4+5*6-7*8+9/10";

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
        vector<char> sumdif_delimiters;
        vector<string> muls_divs = split(input, m_sum_dif, sumdif_delimiters);

        auto numbers = processMulsDivs(muls_divs);

        if (numbers.size() == 1)
            return numbers[0];

        for (size_t i = 0; i != numbers.size(); ++i)
        {
            const auto& number = numbers[i];

            if (i == 0)
                result = number;
            else
            {
                const auto& current_operation_str = sumdif_delimiters[i-1];
                auto operation = makeOperation(current_operation_str);

                result = operation(result, number);
            }
        }
        
        return result;
    }

    vector<string> split(const string& input, const string& delimiters, vector<char>& found_delimiters) const
    {
        vector<string> result;
        
        auto index = input.find_first_of(delimiters);
        size_t previous = 0;
        while (index != std::string::npos)
        {
            // Collect the numbers and mul/div subexpressions first
            result.emplace_back(input.substr(previous, index - previous));

            // Collect the found sum/dif operators
            found_delimiters.emplace_back(input[index]);

            // Try to find the next occurance of the sum/dif operator
            previous = index+1;
            index = input.find_first_of(delimiters, previous+1);
        }

        // need to process the remainigs of the input if the last part was just a number
        result.emplace_back(input.substr(previous, index));

        return result;
    }

    vector<int> processMulsDivs(const vector<string>& muls_divs) const
    {
        vector<int> result;

        for (const auto& expression : muls_divs)
        {
            int current_result = 0;

            vector<char> muldiv_delimiters;
            vector<string> numbers_str = split(expression, m_mul_div, muldiv_delimiters);

            if (numbers_str.size() == 1)
            {
                result.emplace_back(std::stoi(numbers_str[0]));
                continue;
            }

			for (size_t i = 0; i != numbers_str.size(); ++i)
			{
                auto number = std::stoi(numbers_str[i]);

                if (i == 0)
                    current_result = number;
				else
				{
					const auto& current_operation_str = muldiv_delimiters[i - 1];
					auto operation = makeOperation(current_operation_str);

                    current_result = operation(current_result, number);
				}
			}
    
            result.emplace_back(current_result);
        }
         
        return result;
    }

    std::function<int(int, int)> makeOperation(char operation_character) const
    {
        switch (operation_character)
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

class StackSolution
{
public:
    int solve(const string& input)
    {
        auto size = input.size();
        stack<int> processed;

        int number = 0;
        char pending_operation = '+';

        for(size_t i = 0; i != size; ++i)
        {
            auto current = input[i];

            if(isdigit(current))
                number = number * 10 + (current - '0');

            if(i == size - 1 || current == '+' || current == '-' || current == '*' || current == '/')
            {
                switch(pending_operation)
                {
                    case '+':
                        processed.push(number);
                        break;
                    case '-':
                        processed.push(-number);
                        break;
                    case '*':
                    {
                        auto lhs = processed.top();
                        processed.pop();
                        processed.push(lhs * number);
                        break;
                    }
                    case '/':
                    {
                        auto lhs = processed.top();
                        processed.pop();
                        processed.push(lhs / number);
                        break;
                    }
                }
                number = 0;
                pending_operation = current;
            }
        }

        int result = 0;
        while(!processed.empty())
        {
            result += processed.top();
            processed.pop();
        }

        return result;
    }
};

class Solution
{
public:
    int calculate(const string& input)
    {
//      Parser parser;
//      return parser.parse(input);

        StackSolution stackSolution;
        return stackSolution.solve(input);
    }
};

int main()
{
    // std::cout << Solution().calculate(test_str_1) << std::endl;
    // std::cout << Solution().calculate(test_str_2) << std::endl;
    // std::cout << Solution().calculate(test_str_3) << std::endl;
    // std::cout << Solution().calculate(test_str_4) << std::endl;
    // std::cout << Solution().calculate(test_str_5) << std::endl;
    std::cout << Solution().calculate(test_str_6) << std::endl;
}
