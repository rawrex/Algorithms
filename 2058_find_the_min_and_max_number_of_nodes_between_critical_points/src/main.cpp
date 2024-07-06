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
		int min_distance = -1;
		int max_distance = -1;

		int prev_min_value = std::numeric_limits<int>::max();
		int prev_max_value = std::numeric_limits<int>::min();

		// No!
		int prev = 0;

		while (node)
		{
			// current node is local minimum candidate
			if (node->val < prev_min_value)
				; 

			// current node is local maximum candidate
			if (node->val > prev_max_value)
				; 

			// iterate further
			node = node->next;
		}
	}
};

int main()
{

}