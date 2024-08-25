#include <vector>

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
        processIterative(root);
        return m_processed;
    }
    
    void processIterative(TreeNode* root)
    {
        TreeNode* prev = nullptr;
        TreeNode* node = root;

        while(node)
        {
            if(node->left)     
            {
                prev = node;
                node = node->left;
                continue;
            }

            if(node->right)     
            {
                prev = node;
                node = node->right;
                continue;
            }

            m_processed.emplace_back(node->val);
            node = prev;
        }
    }

private:
    vector<int> trivial(TreeNode* root)
    {
        processTrivial(root);
        return m_processed;
    }

    void processTrivial(TreeNode* root)
    {
        if(!root)
            return;

        if(root->left)     
            processTrivial(root->left);

        if(root->right)     
            processTrivial(root->right);

        m_processed.emplace_back(root->val);
    }

private:
    vector<int> m_processed;
};

int main() 
{
    Solution().postorderTraversal(nullptr);
}
