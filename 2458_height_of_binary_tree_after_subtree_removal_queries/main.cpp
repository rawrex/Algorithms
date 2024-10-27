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
			result.emplace_back(process(query));

		return result;
    }

private:
	int collect(TreeNode* node, unsigned level)
	{
		if (!node)
			return level - 1;  // return the last valid level if null

		value_to_level[node->val] = level;
		level_nodes[level].emplace_back(node);

		// Calculate the height of the subtree rooted at this node
		int left_height = collect(node->left, level + 1);
		int right_height = collect(node->right, level + 1);

		int height = std::max(left_height, right_height);
		height_below_node[node] = height - level;

		return height;
	}

	int process(int query)
	{
		auto level = value_to_level[query];

		while (level && level_nodes.count(level) == 1)
			--level;

		int max_height = 0;
		for (auto other_node : level_nodes[level])
		{
			if (query == other_node->val)
				continue;
			
			max_height = std::max(max_height, height_below_node[other_node]);
		}

		return max_height + level;
	}

	unordered_map<int, unsigned> value_to_level;
	unordered_map<unsigned, vector<TreeNode*>> level_nodes;
	unordered_map<TreeNode*, int> height_below_node;
};

int main()
{

}