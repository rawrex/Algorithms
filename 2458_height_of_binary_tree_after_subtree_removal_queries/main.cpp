#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

struct TreeNode 
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct Solution 
{
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) 
	{
		vector<int> result;
		collect(root, 0);

		for (int query : queries)
			result.emplace_back(maxHeight(root, value_to_node[query]));

		return result;
    }

private:
	void collect(TreeNode* node, unsigned level)
	{
		if (!node)
			return;

		value_to_node[node->val] = node;

		++level;
		
		collect(node->left, level);
		collect(node->right, level);
	}

	unsigned maxHeight(TreeNode* node, TreeNode* avoid_node)
	{
		unsigned level = 0;
		height(node, avoid_node, level);

		return level;
	}

	void height(TreeNode* node, TreeNode* avoid_node, unsigned& level)
	{
		if (!node || node == avoid_node)
			return;

		++level;

		height(node->left, avoid_node, level);
		height(node->right, avoid_node, level);
	}

	unordered_map<int, TreeNode*> value_to_node;
};

int main()
{

}