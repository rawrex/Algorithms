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
        // Preallocate
        auto size = input_numbers.size();
        vector<int> result;
        result.reserve(size);
        vector<int> prefixes;
        prefixes.reserve(size);
        vector<int> postfixes;
        postfixes.reserve(size);

        // Prefix to the first element is 1
        // Postfix to the last elemnt is 1 as well
        int current_prefix_product = 1;
        int current_postfix_product = 1;

        // Iterators preparation
        auto iterator = input_numbers.cbegin();
        auto riterator = input_numbers.crbegin();
        auto end = input_numbers.cend();
        auto rend = input_numbers.crend();

        // Fill the prefix, postfix containers
        for(; iterator != end && riterator != rend; ++iterator, ++riterator)
        {
            prefixes.emplace_back(current_prefix_product);
            postfixes.emplace_back(current_postfix_product);

            current_prefix_product *= *iterator;
            current_postfix_product *= *riterator;
        }

        // Correct the order in which the elements are going
        std::reverse(postfixes.begin(), postfixes.end());

        // Fill the result container
        for(size_t i = 0; i != size; ++i)
            result.emplace_back(prefixes[i] * postfixes[i]);

        return result;
    }
};

int main()
{
    vector<int> data {1,2,3,4};
    Solution solution;

    solution.solve(data);
}
