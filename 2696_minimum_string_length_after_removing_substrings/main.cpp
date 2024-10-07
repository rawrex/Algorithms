#include <string>

using namespace std;

struct Solution 
{
    int minLength(string s) 
    {
        for (int i = 0; i != s.size(); ++i)
        {
            if ((s[i] == 'A' && s[i + 1] == 'B') || (s[i] == 'C' && s[i + 1] == 'D'))
            {
                s.erase(i, 2);
                i = -1;
            }
        }

        return s.size();
    }
};

int main()
{
    Solution().minLength("CCCCDDDD");
}