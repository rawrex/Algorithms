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
    Node* m_left;
    Node* m_right;
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
        return -1;
    }
};

int main()
{
    std::cout << Solution().calculate(test_str) << std::endl;
}
