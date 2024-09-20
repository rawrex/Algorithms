#include <string>
#include <deque>

using namespace std;

struct Solution 
{
    string shortestPalindrome(string s) 
    {
        if (s.empty())
            return s;

        m_size = s.size();

        auto found_middle = findPalindromeMiddle(s);

        return makePalindrome(s, found_middle);
    }

private:
    int findPalindromeMiddle(const string& s)
    {
        for (int middle = m_size / 2; middle >= 0; --middle)
        {
            int left_index = middle - 1;
            int right_index = middle + 1;
            while (left_index >= 0 && right_index < m_size && s[left_index] == s[right_index])
            {
                --left_index;
                ++right_index;
            }

            if (left_index < 0)
                return middle;

            left_index = middle - 1;
            right_index = middle;
            while (left_index >= 0 && right_index < m_size && s[left_index] == s[right_index])
            {
                --left_index;
                ++right_index;
            }

            if (left_index < 0)
            {
                m_is_even = true;
                return middle;
            }
        }

        return 0;
    }

    string makePalindrome(const string& input, int middle) const
    {
        deque<char> result;

        for (int i = m_size - 1; i >= middle; --i)
            result.push_front(input[i]);

        for (int i = m_is_even ? middle : middle + 1; i != m_size; ++i)
            result.push_front(input[i]);

        return { std::begin(result), std::end(result) };
    }

    int m_size = 0;
    bool m_is_even = false;
};

int main()
{
    Solution().shortestPalindrome("abbacd");
}
