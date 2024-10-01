#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Solution 
{
    bool canArrange(const vector<int>& numbers, int k) 
    {
        return naive(numbers, k);
    }

private:
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
