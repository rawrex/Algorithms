#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Solution
{
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries)
    {
        // Sort items by price
        std::sort(items.begin(), items.end());

        int max_beauty = 0;
        vector<pair<int, int>> price_to_max_beauty;
        price_to_max_beauty.reserve(items.size());
        for (const auto& item : items)
        {
            max_beauty = std::max(max_beauty, item[1]);
            price_to_max_beauty.emplace_back(item[0], max_beauty);
        }

        for (int& query : queries)
        {
            // Binary search for the highest price <= query
            auto comparator = [](int value, const pair<int, int>& elem) { return value < elem.first; };
            auto iter = upper_bound(std::cbegin(price_to_max_beauty), std::cend(price_to_max_beauty), query, comparator);

            if (iter == price_to_max_beauty.begin())
                // No items with price <= query
                query = 0;
            else
				// Max beauty for the largest price <= query
                query = (iter - 1)->second; 
        }

        return queries;
    }
};


int main()
{
    vector<vector<int>> test{ {1,2},{3,2},{2,4},{5,6},{3,5} };
    vector<int> test_queries{ 1,2,3,4,5,6 };
    Solution().maximumBeauty(test, test_queries);
}