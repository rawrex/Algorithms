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
		std::unordered_map<TreeNode*, int> new_values;

		for (const auto& [level, nodes] : m_levels)
		{
			for (auto parent_node : nodes)
			{
				int sum = 0;
				for (auto another_node : nodes)
				{
					if (parent_node == another_node)
						continue;

					sum += another_node->left ? another_node->left->val : 0;
					sum += another_node->right ? another_node->right->val : 0;
				}

				if (parent_node->left)
					new_values[parent_node->left] = sum;
				if (parent_node->right)
					new_values[parent_node->right] = sum;
			}
		}

		for (const auto& [node, new_val] : new_values)
			node->val = new_val;
	}

private:
	std::unordered_map<unsigned, std::vector<TreeNode*>> m_levels;
};

int main()
{

}