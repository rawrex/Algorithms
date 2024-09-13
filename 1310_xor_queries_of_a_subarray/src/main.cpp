#include <vector>

using namespace std;

struct Solution 
{
    using size_type = vector<vector<int>>::size_type;

    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        size_type size = queries.size();
        vector<int> result(size);

        for (size_type i = 0; i != size; ++i)
            result[i] = processQuery(i, queries, arr);

        return result;
    }

private:
    int processQuery(size_type index, const vector<vector<int>>& queries, const vector<int>& numbers)
    {
        int result = 0;

        for (int left = queries[index][0], right = queries[index][1]; left <= right; ++left)
            result ^= numbers[left];

        return result;
    }
};

int main()
{

}