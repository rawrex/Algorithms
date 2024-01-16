#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> solve(vector<int>& nums) 
    {
       // return naive(nums);
       return prefixPostfix(nums);
    }
private:
    vector<int> naive(const vector<int>& input_numbers)
    {
        vector<int> result;
        size_t n = input_numbers.size();
        result.reserve(n);

        for(size_t i = 0; i != n; ++i)
        {
            int current_product = 1;
            for(size_t j = 0; j != n; ++j)
            {
                if(i == j) continue;
                current_product *= input_numbers[j];
            }
            result.emplace_back(current_product);
        }

        return result;
    }

    vector<int> prefixPostfix(const vector<int>& input_numbers)
    {
        vector<int> result;
        // Preallocate
        result.reserve(input_numbers.size());

        // Prefix to the first element is 1
        // Postfix to the last elemnt is 1 as well
        int current_prefix_product = 1;
        int current_postfix_product = 1;

        // Fill the result with the prefix values
        for(const int i : input_numbers)
        {
            result.emplace_back(current_prefix_product);
            current_prefix_product *= i;
        }

        auto result_riterator = result.rbegin();
        auto result_rend = result.rend();
        auto riterator = input_numbers.crbegin();
        auto rend = input_numbers.crend();

        for(; riterator != rend && result_riterator != result_rend; ++riterator, ++result_riterator)
        {
            *result_riterator = *result_riterator * current_postfix_product;
            current_postfix_product *= *riterator;
        }

        return result;
    }
};

int main()
{
    vector<int> data {1,2,3,4};
    Solution solution;

    solution.solve(data);
}
