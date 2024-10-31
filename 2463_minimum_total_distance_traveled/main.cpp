#include <vector>
#include <ranges>
#include <functional>
#include <algorithm>

using namespace std;

struct Solution
{
	long long minimumTotalDistance(std::vector<int>& robots, std::vector<std::vector<int>>& factories)
	{
		robots_n = robots.size();
		factories_n = factories.size();
		robots_ptr = &robots;
		factories_ptr = &factories;
		memo = std::vector<std::vector<long long>>(robots_n, std::vector<long long>(factories_n, -1));

		std::ranges::sort(robots);
		std::ranges::sort(factories, [](const std::vector<int>& a, const std::vector<int>& b) { return a[0] < b[0]; }); 

		// Start the recursion with the initial state, starting with the first robot and first factory.
		return calculate(0, 0);
	}

private:
	long long calculate(int robot_i, int factory_i)
	{
		// All robots have been processed
		if (robot_i == robots_n)
			return 0;

		// If all factories have been considered and not all robots are assigned, assign high cost
		if (factory_i == factories_n)
			return std::numeric_limits<long long>::max();

		// Already have an answer
		if (memo[robot_i][factory_i] != -1)
			return memo[robot_i][factory_i];

		// Check next factory first
		long long answer = calculate(robot_i, factory_i + 1);
		long long tmp_distance = 0;

		// Try assigning robots to the current factory and calculate the total distance
		for (int i = 0; i < (*factories_ptr)[factory_i][1]; ++i)
		{
			// If all robots are processed
			if (robot_i + i >= robots_n)
				break;

			// Add distance for the current robot
			tmp_distance += std::abs((*robots_ptr)[robot_i + i] - (*factories_ptr)[factory_i][0]);

			// Recursively calculate the minimum total distance for the remaining robots and factories
			long long next_distance = calculate(robot_i + i + 1, factory_i + 1);

			if (next_distance != std::numeric_limits<long long>::max())
				answer = std::min(answer, tmp_distance + next_distance);
		}

		memo[robot_i][factory_i] = answer;
		return answer;
	};

	std::vector<std::vector<long long>> memo;
	std::vector<int>* robots_ptr = nullptr;
	std::vector<std::vector<int>>* factories_ptr = nullptr;
	size_t robots_n = 0;
	size_t factories_n = 0;
};


int main()
{

}