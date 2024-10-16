#include <string>

using namespace std;

struct Solution 
{
    string longestDiverseString(int a, int b, int c) 
    {
        int size = a + b + c;
        string result;
        int a_consequtive = 0;
        int b_consequtive = 0;
        int c_consequtive = 0;

        for (size_t i = 0; i != size; ++i)
        {
            if (((a >= b && a >= c) || b_consequtive == 2 || c_consequtive == 2) && a_consequtive < 2 && a)
            {
				++a_consequtive;
				--a;

				b_consequtive = 0;
				c_consequtive = 0;

				result.push_back('a');
				continue;
            }
            if (((b >= a && b >= c) || a_consequtive == 2 || c_consequtive == 2) && b_consequtive < 2 && b)
            {
				++b_consequtive;
				--b;

				a_consequtive = 0;
				c_consequtive = 0;

				result.push_back('b');
				continue;
            }
            if (((c >= a && c >= b) || a_consequtive == 2 || b_consequtive == 2) && c_consequtive < 2 && c)
            {
				++c_consequtive;
				--c;

				a_consequtive = 0;
				b_consequtive = 0;

				result.push_back('c');
				continue;
            }
        }

        return result;
    }
};

int main()
{
    Solution().longestDiverseString(1, 1, 7);
}