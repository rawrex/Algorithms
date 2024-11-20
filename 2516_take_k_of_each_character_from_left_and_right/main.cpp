#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Solution
{
    int takeCharacters(string s, int k)
    {
        unordered_map<char, int> frequencies;
        for (char ch : s)
            ++frequencies[ch];

        for (char ch : {'a', 'b', 'c'})
        {
            if (frequencies[ch] < k)
                return -1;
        }

        int max_window_n = 0;
        int window_left = 0;
        int size = s.size();

        for (int window_right = 0; window_right < size; ++window_right) 
        {
            char right_ch = s[window_right];
            --frequencies[right_ch];

            // If the current character's count is below k, slide the window
            while (frequencies[right_ch] < k)
            {
				// Increment the count of the char getting out of the window
                char left_ch = s[window_left];
                ++window_left;

                ++frequencies[left_ch];
            }

            // Calculate the maximum valid substring length seen so far
            max_window_n = std::max(max_window_n, window_right - window_left + 1);
        }

        // The result is the size of the string minus the maximum valid substring length
        return size - max_window_n;
    }
};

int main()
{

}