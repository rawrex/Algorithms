#include <cmath>
#include <vector>
#include <unordered_set>

using namespace std;

struct Solution 
{
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) 
    {
        unordered_set<int> prefixes;

        for (int number : arr1) 
            for (; number; number /= 10) 
                prefixes.emplace(number);

        int longest_prefix = 0;

        for (int number : arr2)
        {
            for (; number; number /= 10)
            {
                if (prefixes.contains(number))
                {
                    longest_prefix = std::max(longest_prefix, static_cast<int>(log10(number)) + 1);
                    break;
                }
            }
        }

        return longest_prefix;
    }
};

int main()
{

}