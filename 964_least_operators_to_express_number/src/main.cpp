#include <iostream>

struct Operation
{
    enum class Type { mul, div, plus, minus };

    Operation(const Type& type) : m_type(type) {}

    int apply(int lhs, int rhs)
    {
        switch(m_type)
        {
            case Type::mul:
                return lhs * rhs;
            case Type::div:
                return lhs / rhs;
            case Type::plus:
                return lhs + rhs;
            case Type::minus:
                return lhs - rhs;
        }
    }

    Type m_type;
};

struct Solution
{
    int leastOpsExpessTarget(int x, int target)
    {
        m_x = x;
        m_target = target;

        return firstAttempt(x, target);
    }

private:
    int firstAttempt(int x, int target)
    {
        auto estimation = estimate(x, target);

        int current = x;

        if(current < target)
        {
            search(current, Operation::Type::mul);
            search(current, Operation::Type::plus);
        }
        if(current > target)
        {
            search(current, Operation::Type::minus);
            search(current, Operation::Type::div);
        }

        return 0;
    }

    int search(int current_value, Operation op)
    {
        return 0; 
    }

    int estimate(int x, int target) 
    {
        int e = x;

        for(unsigned i = 0; e < target; ++i)
            e *= x;

        return e;
    }
private:
    int m_x = 0;
    int m_target = 0;
};

int main()
{
    std::cout << Solution().leastOpsExpessTarget(3, 19) << std::endl;
}
