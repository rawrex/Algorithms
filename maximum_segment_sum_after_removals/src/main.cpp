#include <vector>
#include <unordered_map>
#include <iostream>
#include "../../utils/source/print.h"

using namespace std;

// [14, 7, 2, 2, 0]
vector<int> n1 { 1, 2, 5, 6, 1 };
vector<int> q1 { 0, 3, 2, 4, 1 };

// [16, 5, 3, 0]
vector<int> n2 {3,2,11,1};
vector<int> q2 {3,2,1,0};

class Solution 
{
public:
	vector<long long> solve(vector<int>& nums, vector<int>& removeQueries) 
	{
		m_size = nums.size();
		return naive(nums, removeQueries);
	}

private:
	using result_container_t = vector<long long>;

	int m_size;

	std::unordered_map<size_t, int>     m_index_to_left_right_maximums;
	std::unordered_map<size_t, size_t>  m_beg_to_end;
	std::unordered_map<size_t, size_t>  m_end_to_beg;

private:
	vector<long long> naive(vector<int>& nums, vector<int>& queries) noexcept
	{
		vector<long long> result(m_size);

		for(size_t query_index = 0; query_index != m_size; ++query_index)
		{
			auto index = queries[query_index];
			nums[index] = 0;
			 
			result[query_index] = std::max(maxSumLeft(nums, index), maxSumRight(nums, index));
		}
		return result;
	}

	long long maxSumLeft(const vector<int>& nums, int index) const noexcept
	{
		long long current_sum = 0;
		long long max_sum = 0;

		for(/* empty */; index >= 0; --index)
		{
			if(nums[index] != 0)
			{
				current_sum += nums[index];
			}
			else
			{
				max_sum = std::max(max_sum, current_sum);
				current_sum = 0;
			}
		}

		max_sum = std::max(max_sum, current_sum);
		return max_sum;
	}

	long long maxSumRight(const vector<int>& nums, int index) const noexcept
	{
		long long current_sum = 0;
		long long max_sum = 0;

		for(/* empty */; index != m_size; ++index)
		{
			if(nums[index] != 0)
			{
				current_sum += nums[index];
			}
			else
			{
				max_sum = std::max(max_sum, current_sum);
				current_sum = 0;
			}
		}

		max_sum = std::max(max_sum, current_sum);
		return max_sum;
	}
};

int main()
{
	auto result = Solution().solve(n2, q2);
	print(result);
}
