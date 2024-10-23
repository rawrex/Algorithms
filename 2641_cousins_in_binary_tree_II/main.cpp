#include <unordered_map>

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
    TreeNode* replaceValueInTree(TreeNode* root) 
	{
		collect(root, 0);
		update();

		return root;
    }

	void collect(TreeNode* node, unsigned level)
	{
		if (!node)
			return;

		collect(node->left, level + 1);
		collect(node->right, level + 1);

		m_levels[level].emplace_back(node);
	}

	void update()
	{
		std::unordered_map<TreeNode*, int> new_values;

		for (const auto& [level, nodes] : m_levels)
		{
			for (auto node : nodes)
			{
				int sum = 0;
				for (auto another_node : nodes)
				{
					if (node == another_node)
						continue;

					sum += another_node->left ? another_node->left->val : 0;
					sum += another_node->right ? another_node->right->val : 0;
				}

				new_values[node->left] = sum;
				new_values[node->right] = sum;
			}

			for (auto node : nodes)
				node->val = new_values[node];
		}
	}

private:
	std::unordered_map<unsigned, std::vector<TreeNode*>> m_levels;
};

int main()
{

}