#include <string>
#include <vector>

using namespace std;

struct Solution 
{
    int minChanges(std::string_view s) 
    {
        int sum = 0;
        for (const auto& L_R : split(s))
			sum += (L_R[0] == L_R[1]) ? 0 : 1;

        return sum;
    }

private:
    using partitions = std::vector<std::string_view>;

    partitions split(std::string_view str)
    {
        partitions parts;
        for (size_t i = 0; i < str.size(); i += 2)
            parts.emplace_back(str.substr(i, 2));
        return parts;
    }
};

int main()
{
    Solution().minChanges("010010");
}