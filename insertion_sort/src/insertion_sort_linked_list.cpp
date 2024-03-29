#include <iostream>

// 147. Insertion Sort List
// https://leetcode.com/problems/insertion-sort-list/
// Solution analysis 
// https://afteracademy.com/blog/sort-a-linked-list-using-insertion-sort

struct ListNode {
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* head) 
{
	for(auto iter = head; iter; iter=iter->next)
		std::cout << iter->val << ' ';
	std::cout << std::endl;
}

// Define the test list
ListNode node5;
ListNode node4(-4, &node5);
ListNode node3(0, &node4);
ListNode node2(4, &node3);
ListNode node1(8, &node2);
ListNode head(10, &node1);

class Solution
{
	ListNode* insert(ListNode*& sorted_head, ListNode*& new_node)
	{
		// If the sorted_head is a head of an empty list
		// Or if the new_node is smaller than the smallest node in the sorted list
		if (!sorted_head || (sorted_head->val >= new_node->val))
		{
			// Let the new_node to be the new head of the sorted part
			new_node->next = sorted_head;
			return new_node;
		}
		else
		{
			ListNode*& iter = sorted_head;

			// While the next node in the sorted list is present (not a nullptr)
			// And has a value that is less than the value of the new node we add
			// Advance the iter in the sorted list
			for (; iter->next && (iter->next->val < new_node->val); iter=iter->next);
			
			// The iter now either points to the last element in the sorted list
			// Or its (iter) next node has value greater than the value of the new_node

			// Make iter to point to the new_node
			// And new_node now points to the node that was coming after the iter
			new_node->next = iter->next;
			iter->next = new_node;
		}

		return sorted_head;
	}
	
public:
	ListNode* insertionSortList(ListNode* head)
	{
		ListNode* sorted_head = nullptr;
		ListNode* iter = head;

		while (iter)
		{
			// We need to store the next node since it may be overwritten (line 41)
			auto next = iter->next;

			// Insert the iter appropriately
			sorted_head = insert(sorted_head, iter);

			// Advance the iter using pre-stored pointer to the next node
			iter = next;
		}
		return sorted_head;
	}
};


//int main()
//{
//	print(&head);
//	Solution s;
//	ListNode* result = s.insertionSortList(&head);
//	print(result);
//}
