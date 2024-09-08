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
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
		if (!head)
			return {};

		vector<ListNode*> result;
		result.reserve(k);

		size_t total_count = 0;

		for (auto node = head; node; node = node->next)
			++total_count;

		auto part_size = total_count / k;
		auto remainder = total_count % k;

		for (auto node = head; node; node = node->next)
		{
			result.emplace_back(node);

			for (int i = 0; i != part_size && node; ++i)
				node = node->next;

			// We need to put the bigger parts in the front groups
			if (remainder--)
				node = node->next;
		}
			
		return result;
    }
};

int main()
{

}