#include <vector>

using namespace std;

struct Solution
{
    vector<int> decrypt(vector<int>& code, int k)
    {
        int input_size = code.size();
        if (k == 0)
            return vector<int>(input_size, 0);

        vector<int> result(input_size, 0);

        int direction = k > 0 ? 1 : -1;
        k = std::abs(k);

        for (int index = 0; index < input_size; ++index)
        {
            for (int offset = 1; offset <= k; ++offset)
            {
                int target_index = (index + direction * offset + input_size) % input_size;
                result[index] += code[target_index];
            }
        }

        return result;
    }
};


int main()
{
	vector<int> test{ 5,7,1,4 };
	Solution().decrypt(test, 3);
}