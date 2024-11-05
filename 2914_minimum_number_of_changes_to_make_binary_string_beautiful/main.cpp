#include <string>
#include <vector>

using namespace std;

struct Solution 
{
    int minChanges(string s) 
    {
        return process(split(s));
    }

private:
    using partitions = std::vector<std::pair<std::string_view, std::string_view>>;

    int process(const partitions& parts)
    {
        int sum = 0;
        for (const auto& [L, R] : parts)
        {
            if (L.empty() || R.empty())
                continue;

			auto L_size = L.size();
			auto R_size = R.size();

			if (L_size == 1 && R_size == 1)
				sum += (L.back() == R.back()) ? 0 : 1;
			else
				sum += process(split(L)) + process(split(R));
		}
        return sum;
    }

    partitions split(std::string_view str)
    {
        partitions result;

        // Recursively split the string into partitions of even length
        if (str.size() % 2 == 0) 
        {
            auto middle = str.size() / 2;
            result.push_back({ str.substr(0, middle), str.substr(middle) });
        }
        else 
        {
            // Handle odd length by excluding the last character in the left partition
            auto middle = (str.size() - 1) / 2;
            result.push_back({ str.substr(0, middle), str.substr(middle) });
        }

        return result;
    }
};

int main()
{
    Solution().minChanges("010010");
}