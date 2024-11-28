#include <queue>
#include <array>
#include <vector>

using namespace std;

struct Solution 
{
	using T = tuple<int, int, int>;

    int minimumObstacles(vector<vector<int>>& grid) 
	{
		const auto rows = grid.size();
		const auto cols = grid.back().size();

		priority_queue<T, vector<T>, greater<>> min_heap;
		vector<vector<int>> dist(rows, vector<int>(cols, std::numeric_limits<int>::max()));

		min_heap.emplace(grid[0][0], 0, 0);

		dist[0][0] = grid[0][0];

		while (!min_heap.empty()) 
		{
			const auto [distance, i, j] = min_heap.top();
			min_heap.pop();

			if (i == rows - 1 && j == cols - 1)
				return distance;

			for (const auto& [dx, dy] : dirs) 
			{
				auto x = i + dx;
				auto y = j + dy;

				if (x < 0 || x == rows || y < 0 || y == cols)
					continue;

				// Better candidate is found
				if (const int new_distance = distance + grid[i][j]; new_distance < dist[x][y]) 
				{
					dist[x][y] = new_distance;
					min_heap.emplace(new_distance, x, y);
				}
			}
		}

		return dist[rows - 1][cols - 1];
	}

private:
	const static constexpr std::array<std::array<int, 2>, 4> dirs
	{ 
		std::array<int, 2>{0, 1},
		std::array<int, 2>{1, 0},
		std::array<int, 2>{0, -1},
		std::array<int, 2>{-1, 0}
	};
};

int main()
{

}