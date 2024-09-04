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
        else if(command == -2)
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
        else
        {
            switch (direction)
            {
            case 0:
                for (int y_copy = y; y != y_copy + command; ++y)
                {
                    if (isBlocked())
                    {
                        --y;
                        return;
                    }
                }
                return;
            case 1:
                for (int x_copy = x; x != x_copy + command; ++x)
                {
                    if (isBlocked())
                    {
                        --x;
                        return;
                    }
                }
                return;
            case 2:
                for (int y_copy = y; y != y_copy - command; --y)
                {
                    if (isBlocked())
                    {
                        ++y;
                        return;
                    }
                }
                return;
            case 3:
                for (int x_copy = x; x != x_copy - command; --x)
                {
                    if (isBlocked())
                    {
                        ++x;
                        return;
                    }
                }
                return;
            }
        }
    }

    bool isBlocked() const noexcept
    {
        return m_obstacles_x.count(x) && m_obstacles_y.count(y);
    }

    // 0 north, 1 east, 2 south, 3 west
    int direction = 0;
    int x = 0;
    int y = 0;

    set<int> m_obstacles_x;
    set<int> m_obstacles_y;
};

struct Solution 
{
    int robotSim(const vector<int>& commands, const vector<vector<int>>& obstacles) 
    {
        Robot robot(obstacles);

        for (int command : commands)
            robot.move(command);

        return robot.x* robot.x + robot.y * robot.y;
    }
};

int main()
{
    Solution().robotSim({ 6, -1, -1, 6 }, {  });
}