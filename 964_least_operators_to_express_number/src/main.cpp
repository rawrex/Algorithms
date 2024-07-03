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
        m_step = x;
        m_target = target;

		return dfs(target);
	}

private:
	// A recursive function, defined using a lambda, that does the work.
	// It calculates the least number of operations to express 'value'.
	int dfs(int value)
	{
		// If x is greater than or equal to the target value, we calculate the minimum number of operations.
		if (m_step >= value) 
			return min(value * 2 - 1, 2 * (m_step - value));

		// Check if the result has been memoized; if so, return it.
		if (m_memo.count(value)) 
			return m_memo[value];

		int operations_count = 2; // The operation count starts at 2 (representing x/x).
		long long power = m_step * m_step; // Start with x squared.

		// Increase 'power' by multiplying with x until it just exceeds or equals 'value'.
		while (power < value) 
        {
			power *= m_step;
			++operations_count; // Increment operation count each time we multiply with x.
		}

		// Compute the minimum operations if we use 'power' just less than 'value':
		int ans = operations_count - 1 + dfs(value - power / m_step);

		// If the remaining value (power - value) is less than the original 'value',
		// it might be more optimal to also consider this path.
		if (power - value < value) 
			ans = min(ans, operations_count + dfs(power - value));

		// Memoize the answer for 'value'.
		m_memo[value] = ans;
		return ans;
	}

    int m_step = 0;
    int m_target = 0;
	unordered_map<int, int> m_memo;
};

int main()
{
    std::cout << FoundSolution().leastOpsExpressTarget(3, 19) << std::endl;
}
