#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> solve(vector<int>& nums) 
    {
       // return naive(nums);
       // return prefixPostfix(nums);
       return oneLoop(nums);
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

    vector<int> oneLoop(const vector<int>& input_numbers)
    {
        using size_type = vector<int>::size_type;

        // resize is needed due the the fact that we will assing via indices from the tail
        auto size = input_numbers.size();
        vector<int> result;
        result.resize(size);
        vector<int> postfix;
        postfix.resize(size);   
        vector<int> prefix;
        prefix.resize(size);

        // Prefix to the first element is 1
        // Postfix to the last elemnt is 1 as well
        int current_prefix_product = 1;
        int current_postfix_product = 1;

        size_type forward_index = 0;
        size_type backward_index = size - 1;
        size_type middle = size / 2;

        for (; forward_index != size && backward_index >= 0; ++forward_index, --backward_index)
        {
            // we have passed the middle in both directions
            if (forward_index >= middle && backward_index <= middle)
            {
                auto& prefix_number = prefix[forward_index];
                auto& postfix_number = postfix[backward_index];

                prefix_number = current_prefix_product;
                postfix_number = current_postfix_product;

                current_prefix_product *= input_numbers[forward_index];
                current_postfix_product *= input_numbers[backward_index];

                result[forward_index] = prefix[forward_index] * postfix[forward_index];
                result[backward_index] = prefix[backward_index] * postfix[backward_index];
            }
            else
            {
                auto& prefix_number = prefix[forward_index];
                auto& postfix_number = postfix[backward_index];

                prefix_number = current_prefix_product;
                postfix_number = current_postfix_product;

                current_prefix_product *= input_numbers[forward_index];
                current_postfix_product *= input_numbers[backward_index];
            }
        }

        return result;
    }
};

int main()
{
    vector<int> data {1,2,3,4};

    // prefix: { 1, 1, 2, 6 }
    // postfix: { 24, 12, 4, 1 }

    Solution solution;

    solution.solve(data);
}
