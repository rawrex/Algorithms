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
		if (!head)
			return { -1, -1 };

		m_prev_value = head->val;

		if (!head->next)
			return { 1, 1 };
			
		return traverse(head->next);
	}

	vector<int> traverse(ListNode* node)
	{
		for (/* empty */; node; ++m_current_distance, m_prev_value = node->val, node = node->next)
		{
			if (!isCritical(node))
				continue;

			m_record_distance_max = std::max(m_current_distance, m_record_distance_max);
			m_record_distance_min = std::min(m_current_distance, m_record_distance_min);

			m_current_distance = 0;
		}

		return { m_record_distance_min, m_record_distance_max };
	}

	bool isCritical(const ListNode* node) const noexcept
	{
		if (!node->next)
			return false;

		return (node->val < m_prev_value && node->val < node->next->val) || (node->val > m_prev_value && node->val > node->next->val);
	}

private:
	int m_prev_value = 0;
	int m_current_distance = 0;
	int m_record_distance_min = std::numeric_limits<int>::max();
	int m_record_distance_max = std::numeric_limits<int>::min();
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