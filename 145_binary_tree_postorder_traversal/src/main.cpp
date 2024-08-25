#include <stack>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode 
{
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution 
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        // return trivial(root);
        return iterative(root);
    }

private:
    vector<int> iterative(TreeNode* root)
    {
		if (root == nullptr)
			return {};

		vector<int> result;
		stack<TreeNode*> stack{{root}};

		while (!stack.empty()) 
        {
            auto node = stack.top();
            stack.pop();

			result.emplace_back(node->val);

			if (node->left)
				stack.push(node->left);

			if (node->right)
				stack.push(node->right);
		}

        std::reverse(std::begin(result), std::end(result));
		return result;
    }

private:
    vector<int> trivial(TreeNode* root)
    {
        processTrivial(root);
        return m_result;
    }

    void processTrivial(TreeNode* root)
    {
        if(!root)
            return;

        if(root->left)     
            processTrivial(root->left);

        if(root->right)     
            processTrivial(root->right);

        m_result.emplace_back(root->val);
    }

private:
    vector<int> m_result;
};

TreeNode b(3, nullptr, nullptr);
TreeNode a(1, &b, nullptr);
TreeNode root(1, nullptr, &a);

int main() 
{
    Solution().postorderTraversal(&root);
}
