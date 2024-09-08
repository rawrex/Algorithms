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
        vector<ListNode*> result(k, nullptr);

        int total_count = 0;
        for (ListNode* node = head; node; node = node->next)
            ++total_count;

        int part_size = total_count / k;
        int remainder = total_count % k;

        auto node = head;
        for (int i = 0; i < k && node; ++i)
        {
            result[i] = node;

            // Distribute the reaminder
            int current_part_size = part_size + (remainder-- > 0 ? 1 : 0);

            // Move the pointer to the end of the current part
            for (int j = 1; j < current_part_size; ++j)
                if (node) node = node->next;

            // Disconnect the current part from the rest of the list
            if (node)
            {
                ListNode* next_part_node = node->next;
                node->next = nullptr;
                node = next_part_node;
            }
        }

        return result;
    }
};


int main()
{

}