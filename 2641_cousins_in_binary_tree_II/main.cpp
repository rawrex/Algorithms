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

		root->val = 0;

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
		// Precompute the total sum of all node values at each level
		std::unordered_map<unsigned, int> level_sums;

		for (const auto& [level, nodes] : m_levels)
		{
			int total_sum = 0;
			for (const auto& node : nodes)
			{
				if (node->left)
					total_sum += node->left->val;
				if (node->right)
					total_sum += node->right->val;
			}
			level_sums[level] = total_sum;
		}

		// Update the values using precomputed sums
		for (const auto& [level, nodes] : m_levels)
		{
			for (auto parent_node : nodes)
			{
				int sibling_sum = 0;

				sibling_sum += parent_node->left ? parent_node->left->val : 0;
				sibling_sum += parent_node->right ? parent_node->right->val : 0;

				int cousin_sum = level_sums[level] - sibling_sum;

				if (parent_node->left)
					parent_node->left->val = cousin_sum;
				if (parent_node->right)
					parent_node->right->val = cousin_sum;
			}
		}
	}

private:
	std::unordered_map<unsigned, std::vector<TreeNode*>> m_levels;
};

int main()
{

}