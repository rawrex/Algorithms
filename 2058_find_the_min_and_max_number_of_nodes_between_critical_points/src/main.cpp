#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct ListNode
{
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

	int val;
	ListNode* next;
};

struct Solution
{
	vector<int> nodesBetweenCriticalPoints(ListNode* head)
	{
		return traverse(head);
	}

	vector<int> traverse(ListNode* node)
	{
		while (node->next)
		{
			// current node is local minimum
			if (node->val < m_current_min && node->val < node->next->val)
			{
				m_current_min = node->val;

				if (m_current_distance_min > m_record_distance_min)
					m_record_distance_min = m_current_distance_min;
			}

			// current node is local maximum
			if (node->val > m_current_max && node->val > node->next->val)
			{
				m_current_max = node->val;

				if (m_current_distance_max > m_record_distance_max)
					m_record_distance_max = m_current_distance_max;
			}

			++m_current_distance_min;
			++m_current_distance_max;

			// iterate further
			node = node->next;
		}

		return { m_record_distance_min, m_record_distance_max };
	}

private:
	int m_record_distance_min = -1;
	int m_record_distance_max = -1;

	int m_current_distance_min = -1;
	int m_current_distance_max = -1;

	int m_current_min = std::numeric_limits<int>::max();
	int m_current_max = std::numeric_limits<int>::min();
};

// [5,3,1,2,5,1,2]

ListNode a(2, nullptr);
ListNode b(1, &a);
ListNode c(5, &b);
ListNode d(2, &c);
ListNode e(1, &d);
ListNode f(3, &e);
ListNode test_head(5, &f);

int main()
{
	auto result = Solution().nodesBetweenCriticalPoints(&test_head);
	std::cout << result[0] << ' ' << result[1] << std::endl;
}