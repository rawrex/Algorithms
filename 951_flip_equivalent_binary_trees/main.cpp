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

struct Solution1
{
	bool flipEquiv(TreeNode* root1, TreeNode* root2) 
	{
		return isFlipEquivalent(root1, root2);
	}

	bool isFlipEquivalent(TreeNode* root1, TreeNode* root2) 
	{
		if (root1 == root2)
			return true;

		if (!root1 || !root2 || root1->val != root2->val)
			return false;

		return (isFlipEquivalent(root1->left, root2->left) && isFlipEquivalent(root1->right, root2->right)) || (isFlipEquivalent(root1->left, root2->right) && isFlipEquivalent(root1->right, root2->left));
	}
};

struct Solution2
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

	void collect(TreeNode* node, unsigned level, std::unordered_map<unsigned, std::vector<int>>& levels)
	{
		if (!node)
			return;

		collect(node->left, level + 1, levels);
		collect(node->right, level + 1, levels);

		m_max_level = std::max(m_max_level, level);
		levels[level].emplace_back(node->val);
	}

	std::size_t hash(std::vector<uint32_t> const& vec) const 
	{
		std::size_t seed = vec.size();
		for (auto& i : vec)
			seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);

		return seed;
	}

	unsigned m_max_level = 0;
	std::unordered_map<unsigned, std::vector<int>> m_levels1;
	std::unordered_map<unsigned, std::vector<int>> m_levels2;
};

struct Solution
{
	bool flipEquiv(TreeNode* root1, TreeNode* root2)
	{
		return s1.flipEquiv(root1, root2);
		// return s2.flipEquiv(root1, root2);
	}

private:
	Solution1 s1;
	Solution2 s2;
};

int main()
{

}