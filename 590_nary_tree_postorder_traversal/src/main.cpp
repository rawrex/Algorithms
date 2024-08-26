#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

// Definition for a Node.
struct Node 
{
    Node() = default;

    Node(int _val) : val(_val)
    {

    }

    Node(int _val, const vector<Node*>& _children) : val(_val), children(_children)
    {

    }

    int val;
    vector<Node*> children;
};


struct Solution 
{
    vector<int> postorder(Node* root) 
    {
        // return trivial(root);
        return iterative(root);
    }
    
private:
    // Tirvial solution using recursion
    vector<int> trivial(Node* root)
    {
        processTrivial(root);
        return m_result;
    }

    void processTrivial(Node* node)
    {
        if (!node)
            return;

        for (const auto& child : node->children)
            processTrivial(child);

        m_result.emplace_back(node->val);
    }

    vector<int> m_result;

private:
    // Solution using iterative approach
    vector<int> iterative(Node* root) const
    {
        if (!root)
            return {};

        vector<int> result;
        stack<Node*> nodes{ {root} };

        while (!nodes.empty())
        {
            const auto& node = nodes.top();
            nodes.pop();

            result.emplace_back(node->val);

            for (const auto& child : node->children)
                nodes.push(child);
        }

        std::reverse(std::begin(result), std::end(result));
        return result;
    }
};

int main()
{

}
