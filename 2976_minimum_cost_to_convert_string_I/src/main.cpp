#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Solution
{
    struct Translation
    {
        char original_value;
        char changed_value;
        int cost;
    };

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
        auto size = source.size(); 
        long long total_cost = 0;

        for(size_t i = 0; i != size; ++size)
        {
            if(auto iter = original2translation.find(source[i]); iter != original2translation.cend())
            {
                if(iter->second.changed_value == target[i])
                    total_cost += iter->second.cost;
                else if(!recursiveCall(total_cost, iter->second.changed_value))
                    return -1;
            }
            else return -1;
        }
    }

    bool searchTranslationPath(long long& total_cost, 

private:
    unordered_map<char, Translation> original2translation;
};

int main()
{

}
