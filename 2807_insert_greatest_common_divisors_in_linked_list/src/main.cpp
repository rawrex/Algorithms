#include <numeric>

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
		auto current = head;
		auto next = head->next ? head->next : nullptr;

		while (current && next)
		{
			auto divisor = new ListNode(std::gcd(current->val, next->val), next);
			current->next = divisor;
			
			current = next;
			next = next->next;
		}

		return head;
    }
};

int main()
{

}