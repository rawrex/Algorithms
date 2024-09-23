#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Trie 
{
    Trie(const std::vector<std::string>& dictionary)
    {
        buildFromVector(dictionary, this);
    }

    void insert(const std::string& word) 
    {
        Trie* node = this;
        for (char ch : word) 
        {
            if (!node->children.contains(ch)) 
                node->children[ch] = new Trie();

            node = node->children[ch];
        }
        node->m_is_end_of_word = true;
    }

    // Builds a trie from a vector of words
    static void buildFromVector(const std::vector<std::string>& words, Trie* trie) 
    {
        for (const auto& word : words) 
            trie->insert(word);
    }

    // Function to check if there is any word in the trie that starts with the given prefix
    bool startsWith(const std::string& prefix) const 
    {
        const Trie* node = this;
        for (char ch : prefix) 
        {
            if (!node->children.contains(ch)) 
                return false;

            node = node->children.at(ch);
        }
        return true;
    }

private:
    std::unordered_map<char, Trie*> children;
    bool m_is_end_of_word = false;
};


struct Solution 
{
    int minExtraChar(string s, vector<string>& dictionary) 
    {
                        
    }
};

int main()
{

}