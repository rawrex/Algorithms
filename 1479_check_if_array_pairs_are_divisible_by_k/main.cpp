#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Solution 
{
    bool canArrange(const vector<int>& numbers, int k) 
    {
        // return naive(numbers, k);
        return remainders(numbers, k);
    }

private:
    bool remainders(const vector<int>& numbers, int k)
    {
        std::unordered_map<int, int> remainder_count;

		for (const auto& num : numbers)
		{
			int remainder = ((num % k) + k) % k;  
			++remainder_count[remainder];
		}

		for (const auto& [remainder, count] : remainder_count)
		{
            // Special case: remainder 0 must have an even count 
			if (remainder == 0) 
			{
				if (count % 2 != 0)
					return false;
			}
            // For remainder r, there should be remainder k - r
			else  
			{
				int complement = k - remainder;
				if (remainder_count[complement] != count)
					return false;
			}
		}

		return true;
    }

    bool naive(const vector<int>& numbers, int k)
    {
        auto size = numbers.size();
        for (int i = 0; i != size; ++i)
        {
            if (m_used_indices.count(i))
                continue;

            for (int j = i+1; j != size; ++j)
            {
				if (m_used_indices.count(j))
					continue;

                if ((numbers[i] + numbers[j]) % k)
                    continue;

				m_used_indices.emplace(i);
				m_used_indices.emplace(j);
                break;
            }
        }

        return m_used_indices.size() == size;
    }

    std::unordered_set<int> m_used_indices;
};

int main()
{
    Solution().canArrange({ 1,2,3,4,5,10,6,7,8,9 }, 5);
}
