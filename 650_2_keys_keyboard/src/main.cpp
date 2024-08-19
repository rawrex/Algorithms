#include <iostream>

struct Solution
{
	int minSteps(int n)
	{
		if (n == 1)
			return 0;

		m_target = n;

		int current_amount = 2;
		int operations_count = 2;

		return traverse(current_amount, operations_count);
	}

private:
	int traverse(int current_amount, int operations_count)
	{
		if (current_amount > m_target)
			return std::numeric_limits<int>::max();

		if (current_amount == m_target)
			return operations_count;

		if(m_target % current_amount)
			return std::min(m_target / current_amount, traverse(current_amount * 2, operations_count + 2));
		else
			return traverse(current_amount + 1, operations_count + 1);
	}

	int m_target = 0;
};

int main()
{

}