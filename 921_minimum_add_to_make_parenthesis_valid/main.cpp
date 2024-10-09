#include <string>

using namespace std;

struct Solution 
{
    int minAddToMakeValid(string s) const
    {
        int unpaired_open_count = 0;
        int unpaired_close_count = 0;

        for (char ch : s)
        {
            if (ch == '(')
            {
                ++unpaired_open_count;
            }
            else
            {
                if (unpaired_open_count != 0)
                    --unpaired_open_count;
                else
                    ++unpaired_close_count;
            }
        }

        return unpaired_open_count + unpaired_close_count;
    }
};

int main()
{

}