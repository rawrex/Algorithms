#include <vector>

using namespace std;

struct Solution 
{
    int chalkReplacer(const vector<int>& chalk, int k) 
    {
        // Hits time limit
        // return naive(chalk, k);
        return sumFirst(chalk, k);
    }

private:
    int naive(const vector<int>& chalk, int k)
    {
        int size = chalk.size();
        int index = 0;

        for (/* empty */; k > 0; ++index)
        {
            if (index == size)
                index = 0;

            if (k < chalk[index])
                return index;

            k -= chalk[index];
        }

        return index == size ? 0 : index;
    }

    int sumFirst(const vector<int>& chalk, int k)
    {
        long long sum = 0;
        for (int i : chalk)
            sum += i;

        k = k % sum;

        return naive(chalk, k);
    }
};

int main()
{
    Solution().chalkReplacer({3, 4, 1, 2}, 25);
}