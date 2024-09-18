#include <vector>
#include <string>
#include <algorithm>
#include <ranges>

using namespace std;

struct Solution 
{
    string largestNumber(const vector<int>& nums) 
    {
        vector<string> number_strings;
        number_strings.reserve(nums.size());

        for (int i : nums)
            number_strings.emplace_back(std::to_string(i));

        // Compare two strings by concatenating them in different orders
        std::ranges::sort(std::begin(number_strings), std::end(number_strings), [](const string& a, const string& b)
		{
			return a + b > b + a;
		});

        if (number_strings[0] == "0")
            return "0";

        string result;
        for (const auto& num_str : number_strings)
            result.append(num_str);

        return result;
    }
};

int main()
{
    Solution().largestNumber({ 3,30,34,5,9 });
}