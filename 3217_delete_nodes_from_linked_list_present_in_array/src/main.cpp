#include <vector>
#include <unordered_set>

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
	{
		unordered_set<int> nodes(std::begin(nums), std::end(nums));

		auto node = head;
		auto prev = node;

		while (node)
		{
			if (nodes.contains(node->val))
			{
				if (node == head)
					head = node->next;
				else
					prev->next = node->next;
			}
			else
				prev = node;

			node = node->next;
		}

		return head;
    }
};

int main()
{

}