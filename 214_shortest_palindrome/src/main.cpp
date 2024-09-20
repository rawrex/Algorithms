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
        int string_middle = (m_size % 2) ? m_size / 2 : (m_size / 2) - 1;

        auto found_middle = findPalindromeMiddle(s, string_middle);

        return makePalindrome(s, found_middle);
    }

private:
    int findPalindromeMiddle(const string& s, int middle) const
    {
        for (/* empty */; middle; --middle)
        {
            int left_index = middle - 1;
            int right_index = middle + 1;

            for (/* empty */; left_index >= 0 && right_index < m_size; ++right_index, --left_index)
            {
                if (s[left_index] != s[right_index])
                    break;
            }

            if (left_index < 0 || right_index == m_size)
                return middle;
        }

        return 0;
    }

    string makePalindrome(const string& input, int middle) const
    {
        deque<char> result;// (2 * m_size - middle, ' ');

        for (int i = m_size - 1; i != middle; --i)
            result.push_front(input[i]);

        for (int i = middle; i != m_size; ++i)
            result.push_front(input[i]);

        return { std::begin(result), std::end(result) };
    }

    int m_size = 0;
};

int main()
{
    Solution().shortestPalindrome("aacecaaa");
}
