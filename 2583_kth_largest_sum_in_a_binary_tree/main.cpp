#include <set>
#include <algorithm>
#include <unordered_map>

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
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
		collect(root, 0);

		std::vector<long long> sums;
		for (auto& [level, sum] : m_level_sum)
			sums.emplace_back(sum);

		if (sums.size() < k)
			return -1;

		std::nth_element(sums.begin(), sums.begin() + k - 1, sums.end(), std::greater<long long>());
		return *(sums.cbegin() + k - 1);
    }

private:
	void collect(TreeNode* node, unsigned level)
	{
		if (!node)
			return;

		m_level_sum[level] += node->val;
		++level;

		collect(node->left, level);
		collect(node->right, level);
	}

	std::unordered_map<unsigned, long long> m_level_sum;
};

int main()
{

}