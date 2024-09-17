#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Solution 
{
    vector<string> uncommonFromSentences(const string& s1, const string& s2) const
    {
        istringstream iss1(s1);
        istringstream iss2(s2);

        unordered_map<string, unsigned> tracker;

        string word;
        while (std::getline(iss1, word, ' '))
            ++tracker[word];

        while (std::getline(iss2, word, ' '))
            ++tracker[word];

        vector<string> result;
        for (const auto& [w, count] : tracker)
            if (count == 1)
                result.emplace_back(w);

        return result;
    }
};

int main()
{

}