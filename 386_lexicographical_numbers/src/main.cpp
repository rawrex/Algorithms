#include <set>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

struct Solution 
{
    vector<int> lexicalOrder(int n) 
    {
        vector<int> result(n);
        std::iota(std::begin(result), std::end(result), 1);

        auto sorter = [](int a, int b) 
        {
            int a_position = 1;
            for (int i = a; i; i /= 10)
                a_position *= 10;

            int b_position = 1;
            for (int i = b; i; i /= 10)
                b_position *= 10;

            int a_digit = 0;
            int b_digit = 0;
            for (/* empty */; a_position && b_position; a_position /= 10, b_position /= 10)
            {
                a_digit = a / a_position;
                b_digit = b / b_position;

                if (a_digit == b_digit)
                    continue;
            }

            return a_digit < b_digit;
        };

        std::ranges::stable_sort(std::begin(result), std::end(result), sorter);
        return result;
    }
};

int main()
{
    Solution().lexicalOrder(13);
}