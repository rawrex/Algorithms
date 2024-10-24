#include <algorithm>
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
		collect(root1, 0, m_levels1);
		collect(root2, 0, m_levels2);

		return test();
    }

private:
	bool test()
	{
		for (unsigned i = 0; i != m_max_level; ++i)
		{
			auto& a = m_levels1[i];
			auto& b = m_levels2[i];

			if (a == b)
				continue;

			std::reverse(std::begin(b), std::end(b));

			if (a != b)
				return false;
		}

		return true;
	}

	void collect(TreeNode* node, unsigned level, std::unordered_map<unsigned, std::vector<TreeNode*>>& levels)
	{
		if (!node)
			return;

		m_max_level = std::max(m_max_level, level);

		collect(node->left, level + 1, levels);
		collect(node->right, level + 1, levels);

		levels[level].emplace_back(node);
	}

	unsigned m_max_level = 0;
	std::unordered_map<unsigned, std::vector<TreeNode*>> m_levels1;
	std::unordered_map<unsigned, std::vector<TreeNode*>> m_levels2;
};

int main()
{

}