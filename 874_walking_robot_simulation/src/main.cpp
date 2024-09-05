#include <vector>
#include <unordered_set>

using namespace std;

struct Robot
{
    Robot(const vector<vector<int>>& obstacles)
    {
        for (const auto& xy : obstacles)
			m_obstacles.emplace(positionID(xy[0], xy[1]));
    }

    void move(int command)
    {
		if (command == -1)
			turnRight();
		else if (command == -2)
			turnLeft();
		else
			forward(command);

		max_distance = std::max(max_distance, x*x + y*y);
    }

    int distance() const noexcept
    {
		return max_distance;
    }

private:
	int positionID(int x, int y) const noexcept
	{
		return x * 60010 + y;
	}

    bool isCollision() const noexcept
    {
		return m_obstacles.contains(positionID(x, y));
    }

    void forward(int steps) noexcept
	{
		switch (direction)
		{
		case 0:
			for (int i = 0; i != steps; ++i, ++y)
			{
				if (isCollision())
				{
					--y;
					break;
				}
			}
			break;
		case 1:
			for (int i = 0; i != steps; ++i, ++x)
			{
				if (isCollision())
				{
					--x;
					break;
				}
			}
			break;
		case 2:
			for (int i = 0; i != steps; ++i, --y)
			{
				if (isCollision())
				{
					++y;
					break;
				}
			}
			break;
		case 3:
			for (int i = 0; i != steps; ++i, --x)
			{
				if (isCollision())
				{
					++x;
					break;
				}
			}
			break;
		}
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

	int max_distance = 0;

	unordered_set<int> m_obstacles;
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
    Solution().robotSim({ -2,8,3,7,-1 }, { {-4,-1} ,{1,-1},{1,4},{5,0},{4,5},{-2,-1},{2,-5},{5,1},{-3,-1},{5,-3} });
}