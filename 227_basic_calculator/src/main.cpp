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

class Node;
using NodePtr = std::unique_ptr<Node>;

class Node
{
public:
    int eval() const noexcept
    {
        return -1;
    }

private:
    enum class Type { num = 1, op = 2 };
    Type m_type;

    union
    {
        int number;
        Operator op;
    };
    
private:
    NodePtr m_left;
    NodePtr m_right;
};

class Parser
{
public:
    int parse(const string& input) const noexcept
    {
        vector<string> muls_divs;

        string tmp = input;
        auto i = tmp.find_first_of(m_sum_dif);

        while (i != std::string::npos)
        {
            muls_divs.emplace_back(tmp.substr(0, i));
            tmp = tmp.substr(i);

            i = tmp.find_first_of(m_sum_dif, i);
        }

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
