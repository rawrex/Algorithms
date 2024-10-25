#include <vector>
#include <string>
#include <memory>
#include <sstream>
#include <unordered_map>

using namespace std;

class Trie 
{
public:
    struct Node 
    {
        int m_count = 0;
        unordered_map<string, std::unique_ptr<Node>> m_children;
    };

    Trie() : m_root(std::make_unique<Node>()) 
    {
    
    }

    void insert(const string& path)
    {
        Node* current = m_root.get();

        for (const auto& folder : splitPath(path))
        {
            if (!current->m_children.contains(folder))
                current->m_children[folder] = std::make_unique<Node>();

            current = current->m_children[folder].get();
            ++current->m_count;
        }
    }

    int search(const string& path) const 
    {
        int count = 0;
        Node* current = m_root.get();

        for (const auto& folder : splitPath(path))
        {
            if (!current->m_children.contains(folder))
                return count;

            current = current->m_children[folder].get();
            count += current->m_count;
        }

        return count;
    }

private:
    static vector<string> splitPath(const string& path)
    {
        vector<string> output;

        istringstream ss(path);
        string folder;
        std::getline(ss, folder, '/'); // drop the leading '/'
        while (std::getline(ss, folder, '/'))
            output.push_back(folder);

        return output;
    }

    std::unique_ptr<Node> m_root;
};

struct Solution 
{
    vector<string> removeSubfolders(const vector<string>& folders) 
    {
        Trie tree;

        for (const auto& path : folders)
            tree.insert(path);

        return folders;
    }
};

int main()
{

}