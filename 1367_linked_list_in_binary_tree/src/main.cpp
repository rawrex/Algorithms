#include <stack>

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
        // return walkRecursively(root);
        return walkIteratively(root);
    }

private:
    bool walkIteratively(TreeNode* root)
    {
        if (!root)
            return false;

        std::stack<TreeNode*> nodes{{ root }};

        while (!nodes.empty())
        {
            auto node = nodes.top();
            nodes.pop();

            if (checkMatches(m_head, node))
                return true;

            if (node->left)
                nodes.push(node->left);
            if (node->right)
                nodes.push(node->right);
        }

        return false;
    }

    bool checkMatches(ListNode* item, TreeNode* node)
    {
        // Entire list matched
        if (!item)
            return true;

        // Reached a leaf node in the tree without fully matching the list
        if (!node)
            return false;

        if (item->val == node->val)
            return checkMatches(item->next, node->left) || checkMatches(item->next, node->right);

        return false;
    }

    bool walkRecursively(TreeNode* node)
    {
        if (!node)
            return false;

        if (checkMatches(m_head, node))
            return true;

        return walkRecursively(node->left) || walkRecursively(node->right);
    }

    ListNode* m_head;
};

int main()
{

}