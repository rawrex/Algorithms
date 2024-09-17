#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Solution 
{
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        istringstream iss1(s1);
        istringstream iss2(s2);

        unordered_set<string> words1{ istream_iterator<string>{iss1}, istream_iterator<string>{} };
        unordered_set<string> words2{ istream_iterator<string>{iss2}, istream_iterator<string>{} };

        vector<string> result;
        std::set_difference(std::cbegin(words1), std::cend(words1), std::cbegin(words2), std::cend(words2), std::back_inserter(result));

        return result;
    }
};

int main()
{

}