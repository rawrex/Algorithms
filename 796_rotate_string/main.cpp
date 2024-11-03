#include <string>

using namespace std;

struct Solution 
{
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;

        s += s;
        return s.find(goal) != std::string::npos;
    }
};

int main()
{

}
