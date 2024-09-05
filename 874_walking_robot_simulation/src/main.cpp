#include <vector>
#include <set>

using namespace std;

struct Robot
{
    Robot(const vector<vector<int>>& obstacles)
    {
        for (auto& xy : obstacles)
        {
            m_obstacles_x.emplace(xy[0]);
            m_obstacles_y.emplace(xy[1]);
        }
    }

    void move(int command)
    {
		if (command == -1)
			turnRight();
		else if (command == -2)
			turnLeft();
		else
			forward(command);
    }

    int distance() const noexcept
    {
        return max_distance_x * max_distance_x + max_distance_y * max_distance_y;
    }

private:
    bool isBlocked() const noexcept
    {
        return m_obstacles_x.count(x) && m_obstacles_y.count(y);
    }

    void forward(int steps) noexcept
	{
		switch (direction)
		{
		case 0:
			for (int y_copy = y; y != y_copy + steps; ++y)
			{
				if (isBlocked())
				{
					--y;
					break;
				}
			}
			break;
		case 1:
			for (int x_copy = x; x != x_copy + steps; ++x)
			{
				if (isBlocked())
				{
					--x;
					break;
				}
			}
			break;
		case 2:
			for (int y_copy = y; y != y_copy - steps; --y)
			{
				if (isBlocked())
				{
					++y;
					break;
				}
			}
			break;
		case 3:
			for (int x_copy = x; x != x_copy - steps; --x)
			{
				if (isBlocked())
				{
					++x;
					break;
				}
			}
			break;
		}

		max_distance_x = std::max(max_distance_x, std::abs(x));
		max_distance_y = std::max(max_distance_y, std::abs(y));
	}

    void turnRight() noexcept
    {
		switch (direction)
		{
		case 0:
			direction = 1;
			return;
		case 1:
			direction = 2;
			return;
		case 2:
			direction = 3;
			return;
		case 3:
			direction = 0;
			return;
		}
    }

    void turnLeft() noexcept
    {
		switch (direction)
		{
		case 0:
			direction = 3;
			return;
		case 1:
			direction = 0;
			return;
		case 2:
			direction = 1;
			return;
		case 3:
			direction = 2;
			return;
		}
    }

    // 0 north, 1 east, 2 south, 3 west
    int direction = 0;
    int x = 0;
    int y = 0;

    int max_distance_x = std::numeric_limits<int>::min();
    int max_distance_y = std::numeric_limits<int>::min();

    set<int> m_obstacles_x;
    set<int> m_obstacles_y;
};

struct Solution 
{
    int robotSim(const vector<int>& commands, const vector<vector<int>>& obstacles) const
    {
        Robot robot(obstacles);

        for (int command : commands)
            robot.move(command);

        return robot.distance();
    }
};

int main()
{
    Solution().robotSim({ 6, -1, -1, 6 }, {  });
}