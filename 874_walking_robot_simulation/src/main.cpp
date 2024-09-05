#include <vector>
#include <array>
#include <utility>
#include <unordered_set>
#include <algorithm>

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
    int64_t positionID(int x, int y) const noexcept
    {
        // Use 64-bit int to avoid overflow
        return static_cast<int64_t>(x) * 60010 + y; 
    }

    bool isCollision(int newX, int newY) const noexcept
    {
        return m_obstacles.contains(positionID(newX, newY));
    }

    void forward(int steps) noexcept
    {
        for (int i = 0; i != steps; ++i)
        {
            int new_x = x + directions[direction].first;
            int new_y = y + directions[direction].second;

            if (isCollision(new_x, new_y))
                break;

            x = new_x;
            y = new_y;
        }
    }

    void turnRight() noexcept
    {
        direction = (direction + 1) % 4;
    }

    void turnLeft() noexcept
    {
        direction = (direction + 3) % 4;
    }

    // 0 north, 1 east, 2 south, 3 west
    static const array<pair<int, int>, 4> directions;

    int direction = 0;
    int x = 0;
    int y = 0;

    int max_distance = 0;
    unordered_set<int64_t> m_obstacles;  // Use 64-bit integer for obstacle positions
};

const array<pair<int, int>, 4> Robot::directions = 
{
    pair<int, int>(0, 1),
    pair<int, int>(1, 0),
    pair<int, int>(0, -1),
    pair<int, int>(-1, 0)
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