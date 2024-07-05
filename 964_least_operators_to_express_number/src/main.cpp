#include <iostream>
#include <functional>
#include <unordered_map>

using namespace std;

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

class FoundSolution
{
public:
	int leastOpsExpressTarget(int x, int target) 
    {
        m_x = x;
		return depthFirstSearch(target);
	}

private:
	int depthFirstSearch(int value)
	{
		// If x is greater than or equal to the target value, we calculate the minimum number of operations.
        if (m_x >= value)
        {
            // To get to the value, we use m_x/m_x to get a unit (1, each of which takes one operation, division),
            // then we use addition (plus one operation), for each next unit in the value,
            // thus, for each unit (except for the very first one) in the value we use two operations
			auto a = value * 2 - 1;

            // To get to the value we use the same m_x/m_x to get a unit (1, each takes one operation, division)
            // each such unit then subtracted, which adds another operation, 
            // thus, for each unit in the difference we need two operations
			auto b = 2 * (m_x - value);

			return min(a, b);
        }

		// Check if the result has been memoized
        if (auto iter = m_memo.find(value); iter != m_memo.cend())
            return iter->second;

        // The operation count starts at 2, representing x * x
		int operations_count = 2;      

        // Start with x squared.
		long long exponent = m_x * m_x; 

		// Exponentiate until we just overshoot (or hit rigth at) the target value
        for (/* empty */; exponent < value; ++operations_count)
			exponent *= m_x;

		// Compute the minimum operations if we use an "exponent" before the overshoot
        // So, we "undo" one multiplication from the above (hence, the operations_count-1)
        // And then we recursively consider the number of operations for the case where the exponent being just before the overshoot (hence, the exponent/m_x)
		auto current_answer = (operations_count - 1) + depthFirstSearch(value - exponent/m_x);

        // Consdier is it being more optimal to get to the current "value" by constructing a complement, the "exponent - value"
		// If the remaining value (exponent-value) is less than the original "value", it may be optimal to consider this path
		if ((exponent - value) < value) 
			current_answer = min(current_answer, operations_count + depthFirstSearch(exponent - value));

		// Memoize the current_answerwer for the current "value"
		m_memo[value] = current_answer;

		return current_answer;
	}

    int m_x = 0;
	unordered_map<int, int> m_memo;
};

int main()
{
    std::cout << FoundSolution().leastOpsExpressTarget(3, 19) << std::endl;
}
