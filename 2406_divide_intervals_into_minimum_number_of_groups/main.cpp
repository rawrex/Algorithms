#include <map>
#include <vector>

using namespace std;

struct Solution 
{
    int minGroups(vector<vector<int>>& intervals) 
    {
        map<int, int> tracker;
        for (const auto& interval : intervals)
        {
            ++tracker[interval[0]];
			--tracker[interval[1] + 1];
        }

        int groups_counter = 0;
        int max_groups_counter = 0;

        for (const auto& [value, counter] : tracker)
        {
            groups_counter += counter;
            max_groups_counter = std::max(max_groups_counter, groups_counter);
        }

        return max_groups_counter;
    }
};

int main()
{

}