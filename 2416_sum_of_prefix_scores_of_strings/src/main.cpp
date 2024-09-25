#include <vector>
#include <string>
#include <memory>
#include <unordered_map>

using namespace std;

class Trie 
{
public:
    struct Node 
    {
        int m_count = 0;
        unordered_map<char, std::unique_ptr<Node>> m_children;
    };

    Trie() : m_root(std::make_unique<Node>()) 
    {
    
    }

    void insert(const string& str)
    {
        Node* current = m_root.get();

        for (char ch : str)
        {
            ++current->m_count;

            if (!current->m_children.contains(ch))
                current->m_children[ch] = std::make_unique<Node>();

            current = current->m_children[ch].get();
        }
    }

    // Search for a complete integer in the trie
    int search(const string& word) const 
    {
        int count = 0;
        Node* current = m_root.get();

        for (char ch : word)
        {
            count += current->m_count;

            if (!current->m_children.contains(ch))
                return count;

            current = current->m_children[ch].get();
        }

        return count;
    }

private:
    std::unique_ptr<Node> m_root;
};


struct Solution 
{
    vector<int> sumPrefixScores(vector<string>& words) 
    {
        vector<int> result;
        Trie prefix_tree;

        for (const auto& word : words)
            prefix_tree.insert(word);

        for (const auto& word : words)
        {
            auto count = prefix_tree.search(word);
            if (count)
                result.emplace_back(count);
        }

        return result;
    }
};