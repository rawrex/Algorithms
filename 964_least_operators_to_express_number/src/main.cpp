#include <iostream>

struct Solution
{
    int leastOpsExpessTarget(int x, int target)
    {
        return firstAttempt(x, target);
    }
private:
    int firstAttempt(int x, int target)
    {
        return estimate(x, target);
    }

    int estimate(int x, int target) 
    {
        int e = x;

        for(unsigned i = 0; e < target; ++i)
            e *= x;

        return e;
    }
};

int main()
{
    std::cout << Solution().leastOpsExpessTarget(3, 19) << std::endl;
}
