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

        // Count the total number of nodes
        size_t total_count = 0;
        for (auto node = head; node; node = node->next)
            ++total_count;

        auto part_size = total_count / k;
        auto remainder = total_count % k;

        auto node = head;
        for (int i = 0; i < k && node; ++i)
        {
            result[i] = node;

            int current_part_size = part_size + (remainder-- > 0 ? 1 : 0);

            for (int j = 1; j != current_part_size && node; ++j)
                node = node->next;

            // Move to the next part
            if (node)
            {
                auto next_part_node = node->next;
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