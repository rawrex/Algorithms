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
		process(head);
		return m_result;
    }
		
private:
	void process(ListNode* node)
	{
		
	}

	vector<ListNode*> m_result;
};

int main()
{

}