#include <string>
#include <iostream>

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
    explicit Parser(const string& input) noexcept : m_raw_data(input) {}

    NodePtr parse() const noexcept
    {
        return nullptr;
    }

private:
    const std::string& m_raw_data;
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
        Parser parser(input);

        auto root = parser.parse();

        return root->eval();
    }
};

int main()
{
    std::cout << Solution().calculate(test_str) << std::endl;
}
