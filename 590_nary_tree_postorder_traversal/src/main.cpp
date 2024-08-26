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

    }
};

int main()
{

}
