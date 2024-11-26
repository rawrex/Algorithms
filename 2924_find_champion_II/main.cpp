#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Solution 
{
    int findChampion(int n, vector<vector<int>>& edges) 
    {
        vector<int> incoming_degree(n, 0);

        for (const auto& edge : edges) 
            ++incoming_degree[edge[1]];

		// A candidate node for champion
        int champion = -1;
        int zero_incoming_count = 0;

        // Iterate through all nodes to find the node with 0 in-degree, if any
        for (int index = 0; index < n; ++index) 
        {
            // A node with 0 in-degree can be a candidate for champion
            if (incoming_degree[index] == 0) 
            { 
                ++zero_incoming_count;
                champion = index;
            }
        }

        return zero_incoming_count == 1 ? champion : -1;
    }
};

int main()
{

}