#include <numeric>

struct Solution 
{
    int findKthNumber(int n, int k) 
    {
        m_upper_limit = n;

        // Smallest lexicographical number
        long long current_prefix = 1;
        // Considering we will work with 0-indexed
        --k;

        while (k) 
        {
            int count = countNumbersWithPrefix(current_prefix);

            // If k is still larger than the count, skip the entire subtree
            if (k >= count) 
            {
                k -= count;
                ++current_prefix; 
            }
            // If k is within the range, go deeper into the subtree
            else 
            {
                // Decrement k as we have found another smaller number
                --k; 
                // Append a 0 to dive into the next level of the tree
                current_prefix *= 10; 
            }
        }

        return static_cast<int>(current_prefix); 
    }

    // This helper method will count the numbers with a given prefix up to the upper limit.
    int countNumbersWithPrefix(long long prefix) 
    {
        // Get the next prefix by adding one
        long long next_prefix = prefix + 1;

        // The count of numbers with the current prefix
        int count = 0;

        // Calculate the count of the numbers with the current prefix within the bounds of 'n'
        while (prefix <= m_upper_limit) 
        {
            // Add the minimum of the range to the current prefix or the numbers until 'n'
            count += std::min(static_cast<long long>(m_upper_limit) - prefix + 1, next_prefix - prefix);
 
            // Move to the next level
            next_prefix *= 10;
            prefix *= 10;
        }
        return count;
    }

    // This will store the upper limit upto which we need to find the numbers.
    int m_upper_limit;
};

int main()
{

}