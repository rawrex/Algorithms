#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

struct Solution 
{
    bool checkInclusion(const string& permutations, string contains) 
    {
        vector<int> counters(26, 0);

        for (char c : permutations)
            ++counters[c - 'a'];

        int remains = permutations.size();
        for (int left = 0, right = 0; right < contains.size(); ++right) 
        {
            // Right boundary of the window expanding
            auto& right_counter = counters[contains[right] - 'a'];
            --right_counter;

            // If a character is present in "contains"
            // And is also required by permutations, decrementing it will reduce the count of the total characters required
            if (right_counter >= 0)
                --remains;

            // Left boundary contraction
            while (remains == 0) 
            {
                // If the size of the sliding window is the same as the permutations string
                if ((right - left + 1) == permutations.size())
                    return true;

                // The window is shrunk by moving the left pointer
                // Before incrementing left, increment the counter for the character at left
                // If this counter becomes positive, remains is incremented, as one character is now unmatched
                auto& left_counter = counters[contains[left++] - 'a'];
                if (++left_counter > 0)
                    ++remains;
            }
        }
        return false;
    }
};

int main()
{
    Solution().checkInclusion("adc", "dcda");
}