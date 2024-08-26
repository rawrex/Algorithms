#include <iostream>
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
        process(root);
        return m_result;
    }

private:
    void process(Node* node)
    {
        if (!node)
            return;

        for (const auto& child : node->children)
            process(child);

        m_result.emplace_back(node->val);
    }

    vector<int> m_result;
};

int main()
{

}
