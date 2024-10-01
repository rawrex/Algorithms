#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Solution 
{
    bool canArrange(vector<int>& numbers, int k) 
    {
        return naive(numbers, k);
    }

private:
    bool naive(vector<int>& numbers, int k)
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
            }
        }

        return m_used_indices.size() != size;
    }

    std::unordered_set<int> m_used_indices;
};

int main()
{

}
