#include <vector>
#include <string>
#include <memory>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Trie
{
public:
    struct Node
    {
        bool is_terminal = false;
        unordered_map<string, std::unique_ptr<Node>> m_children;
    };

    Trie() : m_root(std::make_unique<Node>()) {}

    void insert(const string& path)
    {
        Node* current = m_root.get();
        for (const auto& folder : splitPath(path))
        {
            if (!current->m_children.contains(folder))
                current->m_children[folder] = std::make_unique<Node>();

            current = current->m_children[folder].get();
        }

        // Mark end of a unique folder path
        current->is_terminal = true;  
    }

    void collectPaths(vector<string>& result, const string& path = "", Node* node = nullptr)
    {
        if (!node) node = m_root.get();

        // Collect the path to this non-terminal node and return
        if (node->is_terminal)
            return result.push_back(path);

        for (const auto& [folder, child] : node->m_children)
            collectPaths(result, path + "/" + folder, child.get());
    }

private:
    static vector<string> splitPath(const string& path)
    {
        vector<string> output;
        istringstream ss(path);
        string folder;
        std::getline(ss, folder, '/');  // Drop the leading '/'
        while (std::getline(ss, folder, '/'))
            output.push_back(folder);

        return output;
    }

    std::unique_ptr<Node> m_root;
};

struct Solution
{
    vector<string> removeSubfolders(vector<string>& folders)
    {
        Trie tree;

        for (const auto& folder : folders)
            tree.insert(folder);

        folders.clear();
        tree.collectPaths(folders);

        return folders;
    }
};

int main()
{

}