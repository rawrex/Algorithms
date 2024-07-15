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
        // Explicit test for the requirement for amount of nodes
		if (!head || !head->next || !head->next->next || !head->next->next->next)
			return { -1, -1 };

		m_prev_value = head->val;

		return traverse(head->next);
	}

	vector<int> traverse(ListNode* node)
	{
		for (int current_index = 0; node != nullptr; ++current_index, m_prev_value = node->val, node = node->next)
		{
			if (isCritical(node))
			{
				if (m_first_index == -1)
					m_first_index = current_index;
				else	
					m_min_distance = std::min(current_index - m_previous_index, m_min_distance);
				m_previous_index = current_index;
			}
		}

		// None or only one critical point
		if (m_first_index == m_previous_index)
			return { -1, -1 };

		return { m_min_distance, m_previous_index - m_first_index };
	}

	bool isCritical(const ListNode* node) const noexcept
	{
		if (!node->next)
			return false;

		return (node->val < m_prev_value && node->val < node->next->val) || (node->val > m_prev_value && node->val > node->next->val);
	}

private:
	int m_prev_value = 0;

	int m_first_index = -1;
	int m_previous_index = -1;
	int m_min_distance = std::numeric_limits<int>::max();
};

// [5,3,1,2,5,1,2]

ListNode a(2, nullptr);
ListNode b(1, &a);
ListNode c(5, &b);
ListNode d(2, &c);
ListNode e(1, &d);
ListNode f(3, &e);
ListNode test_head(5, &f);

ListNode a_2(1, nullptr);
ListNode test_head_2(3, &a_2);

ListNode a_3(2, nullptr);
ListNode b_3(3, &a_3);
ListNode c_3(3, &b_3);
ListNode test_head_3(2, &c_3);

// [1,3,2,2,3,2,2,2,7]
ListNode h_4(7, nullptr);
ListNode g_4(2, &h_4);
ListNode f_4(2, &g_4);
ListNode e_4(2, &f_4);
ListNode d_4(3, &e_4);
ListNode c_4(2, &d_4);
ListNode b_4(2, &c_4);
ListNode a_4(3, &b_4);
ListNode test_head_4(1, &a_4);
int main()
{
//	auto result = Solution().nodesBetweenCriticalPoints(&test_head);
//	auto result = Solution().nodesBetweenCriticalPoints(&test_head_2);
	auto result = Solution().nodesBetweenCriticalPoints(&test_head_3);
//	auto result = Solution().nodesBetweenCriticalPoints(&test_head_4);
	std::cout << result[0] << ' ' << result[1] << std::endl;
}
