#include <stack>
#include <string>

using namespace std;

struct Solution 
{
    int minAddToMakeValid(string s) 
    {
        int count = 0;
        std::stack<char> opened;

        for (char ch : s)
        {
            if (ch == '(')
                opened.push(1);
            else
            {
                if (!opened.empty())
                    opened.pop();
                else
                    ++count;
            }
        }

        return count + opened.size();
    }
};

int main()
{

}