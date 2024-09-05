#include <vector>
#include <numeric>

using namespace std;

struct Solution 
{
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
        int m = rolls.size();

        // Accumulate the sum of the known values
        int sum_of_known = accumulate(begin(rolls), end(rolls), 0);

        // Algebraically express the sum of the unknown values
        int seek_sum = mean * (m + n) - sum_of_known;

        // If the sum we seek is greater than the greatest value we can achieve
        // Or lesser than the least value we can achive
        if (seek_sum > (6 * n) || seek_sum < n)
            return {};

        // Create the result vector with starting values
        // Which we get by integer division of the seek_sum by the n (the number of remaining rolls)
        // Note the overwrite of the input
        rolls = vector<int>(n, seek_sum / n);

        // Distribute the remainder of the values evenly across some number of first elements
        for (int i = 0; i < seek_sum % n; ++i) 
            ++rolls[i];

        return rolls;
    }
};

int main()
{

}