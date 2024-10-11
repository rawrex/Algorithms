#include <map>
#include <queue>
#include <vector>

using namespace std;

struct Solution 
{
    int smallestChair(vector<vector<int>>& times, int target_friend) 
    {
        multimap<int, size_t> leave_times_to_chair; // leave times are not unique
        map<int, size_t> arriaval_times_to_index;   // arrival times are unique
        priority_queue<int, vector<int>, greater<int>> free_chairs;

        // Collect the indices sorted by the according arrival times
        // And the free chairs
        for (size_t i = 0; i < times.size(); ++i)
        {
            arriaval_times_to_index[times[i][0]] = i;
            free_chairs.push(i);
        }

        // For each friend, starting with the earliest to arrive
        // Check if there are those who have alrady departured and occupy the least numbered chair
        for (const auto& [arrival_time, index] : arriaval_times_to_index)
        {
            while (!leave_times_to_chair.empty() && arrival_time >= leave_times_to_chair.begin()->first)
            {
                free_chairs.push(leave_times_to_chair.begin()->second);
                leave_times_to_chair.erase(leave_times_to_chair.begin());
            }

            auto current_chair = free_chairs.top();
            free_chairs.pop();

            if (index == target_friend)
                return current_chair;

            auto leave_time = times[index][1];
			leave_times_to_chair.emplace(leave_time, current_chair);
        }

        return 0;
    }
};

int main()
{

}