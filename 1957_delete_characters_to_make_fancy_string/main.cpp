#include <string>

using namespace std;

struct Solution
{
    string makeFancyString(string s) 
    {
        if (s.size() < 3)
			return s;

		auto answer = s;
		answer.clear();

		for (char ch : s)
		{
			if (answer.size() < 2 || !(answer[answer.size() - 1] == ch && answer[answer.size() - 2] == ch))
				answer.push_back(ch);
		}
	
		return answer;
    }
};

int main()
{
    Solution().makeFancyString("aaabaaaa");
}