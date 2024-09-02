#include <vector>

using namespace std;

struct Solution 
{
    int chalkReplacer(const vector<int>& chalk, int k) 
    {
        int size = chalk.size();
        int index = 0;

        while (k > 0)
        {
            if (index == size)
                index = 0;

            if (k < chalk[index])
                return index;

            k -= chalk[index];
            ++index;
        }

        return index == size ? 0 : index;
    }
};

int main()
{
    Solution().chalkReplacer({3, 4, 1, 2}, 25);
}