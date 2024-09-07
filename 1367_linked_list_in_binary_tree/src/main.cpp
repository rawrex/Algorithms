struct ListNode
{
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

	int val;
	ListNode* next;
};


struct TreeNode
{
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

	int val;
	TreeNode* left;
	TreeNode* right;
};

struct Solution 
{
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
		m_head = head;
		return process(head, root);
    }

private:
	bool process(ListNode* item, TreeNode* node)
	{
		if (!item)
			return true;

		if (!node && item)
			return false;

		if (item->val == node->val)
		{
			return process(item->next, node->left) || process(item->next, node->right);
		}
		else
		{
			item = m_head;
			return process(item, node->left) || process(item, node->right);
		}
	}

	ListNode* m_head;
};

int main()
{

}