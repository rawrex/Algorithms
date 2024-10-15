#include <string>

using namespace std;

struct Solution 
{
    long long minimumSteps(string s) 
    {
        long long count = 0;
        int current_count = 0;

        for (int index = s.size() - 1; index >= 0; --index)
        {
            if (s[index] == '0')
                ++current_count;
            else
                count += current_count;
        }
        
        return count;
    }
};

int main()
{

}