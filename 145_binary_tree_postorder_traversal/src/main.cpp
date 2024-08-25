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
        process(root);
        return m_processed;
    }

    void process(TreeNode* root)
    {
        if(!root)
            return;

        if(root->left)     
            process(root->left);

        if(root->right)     
            process(root->right);

        m_processed.emplace_back(root->val);
    }

private:
    vector<int> m_processed;
};

int main() 
{
    Solution().postorderTraversal(nullptr);
}
