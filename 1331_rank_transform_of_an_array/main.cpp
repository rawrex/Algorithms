#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Solution 
{
    vector<int> arrayRankTransform(vector<int>& input)
    {
        // return first(input);
        // return second(input);
        return third(input);
    }

private:
    vector<int> first(vector<int>& input) 
    {
        std::set<int> unique { std::begin(input), std::end(input) };
        std::map<int, int> number2rank;

        int rank = 0;
        for (int i : unique)
            number2rank[i] = ++rank;

        for (auto& i : input)
            i = number2rank[i];

        return input;
    }

    vector<int> second(vector<int>& input) 
    {
        vector<int> ranks;

        vector<int> sorted = input;
        std::sort(std::begin(sorted), std::end(sorted));
        sorted.erase(unique(std::begin(sorted), std::end(sorted)), std::end(sorted));

        for (int element : input) 
        {
            int rank = upper_bound(std::begin(sorted), std::end(sorted), element) - sorted.begin();
            ranks.push_back(rank);
        }

        return ranks;
    }

    vector<int> third(vector<int>& input) 
    {
        vector<int> sorted = input;
        std::sort(std::begin(sorted), std::end(sorted));
        sorted.erase(unique(std::begin(sorted), std::end(sorted)), std::end(sorted));

        for (auto& i : input) 
            i = upper_bound(std::cbegin(sorted), std::cend(sorted), i) - sorted.cbegin();

        return input;
    }
};