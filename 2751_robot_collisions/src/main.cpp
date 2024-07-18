#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

struct Robot
{
	Robot(int i, int pos, int hp, char dir) noexcept : m_original_index(i), m_position(pos), m_hp(hp), m_increment(dir == 'R' ? 1 : -1)
	{

	}

	int onTick() noexcept
	{
		m_position += m_increment;
        return m_position;
	}

	int position() const noexcept
	{
		return m_position;
	}

	int originalPosition() const noexcept
	{
		return m_original_index;
	}

	int hp() const noexcept
	{
		return m_hp;
	}

	char direction() const noexcept
	{
		return m_increment == -1 ? 'L' : 'R';
	}

	void kill() noexcept
	{
		m_hp = 0;
	}

	void damage() noexcept
	{
		--m_hp;
	}

	bool isDead() const noexcept
	{
		return m_hp == 0;
	}

private:
	int m_original_index = 0;
	int m_position = 0;
	int m_hp = 0;
	int m_increment = 0;
};
    
struct Scene
{
	Scene(const std::vector<int>& p, const std::vector<int>& hp, const std::string& d)
	{
		auto size = static_cast<int>(p.size());

		for (int i = 0; i != size; ++i)
			m_robots.emplace_back(i, p[i], hp[i], d[i]);
	}

	void tick()
	{
		unordered_map<int, Robot*> current_positions;
		//            unordered_map<int, Robot*> new_positions;

		for (auto& current_robot : m_robots)
		{
			if (current_robot.isDead())
				continue;

			current_positions.emplace(current_robot.position(), &current_robot);
		}

		for (auto& current_robot : m_robots)
		{
			if (current_robot.isDead())
				continue;

			auto current_robot_new_position = current_robot.onTick();

			if (!current_positions.emplace(current_robot_new_position, &current_robot).second)
			{
				auto& other_robot_ptr = current_positions[current_robot_new_position];

				if (other_robot_ptr->isDead())
					continue;

				if (other_robot_ptr->direction() != current_robot.direction())
					collide(current_robot, *other_robot_ptr);
			}

			//                if(!new_positions.emplace(new_position, &current_robot).second)
			//                {
			//                    auto& other_robot_ptr = new_positions[new_position];
			//                    if(other_robot_ptr->direction() != current_robot.direction() && !other_robot_ptr->isDead())
			//                        collide(current_robot, *other_robot_ptr);
			//                }
		}
	}

	void collide(Robot& a, Robot& b) const noexcept
	{
		if (a.hp() == b.hp())
		{
			a.kill();
			b.kill();
			return;
		}
		if (a.hp() < b.hp())
		{
			a.kill();
			b.damage();
			return;
		}
		else
		{
			a.damage();
			b.kill();
			return;
		}
	}

	bool done()
	{
		int max_left_position = std::numeric_limits<int>::min();
		int min_right_position = std::numeric_limits<int>::max();

		for (const auto& robot : m_robots)
		{
			if (robot.isDead())
				continue;

			if (robot.direction() == 'L')
				max_left_position = std::max(robot.position(), max_left_position);
			else
				min_right_position = std::min(robot.position(), min_right_position);
		}

		// There are no left-moving robots in front of any of the right moving
		return max_left_position < min_right_position;
	}

	std::vector<int> finish() const
	{
		std::vector<Robot> alive;

		for (auto& robot : m_robots)
			if (!robot.isDead())
				alive.emplace_back(robot);

		std::sort(alive.begin(), alive.end(), [](const auto& a, const auto& b) { return a.originalPosition() < b.originalPosition(); });

		std::vector<int> result;
		for (const auto& r : alive)
			result.emplace_back(r.hp());

		return result;
	}

	vector<Robot> m_robots;
};

vector<int> naive(vector<int>& positions, vector<int>& healths, string directions)
{
	Scene scene(positions, healths, directions);

	while (!scene.done())
		scene.tick();

	return scene.finish();
}

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) 
    {
        return stackSolution(positions, healths, directions);
    }

private:
	struct Robot
	{
		int index = 0;
		int pos = 0;
		int hp = 0;
		char dir = 0;
	};

    vector<int> stackSolution(const vector<int>& positions, const vector<int>& healths, const string& directions)
    {
		m_healths = healths;
        auto size = positions.size();

        for (int i = 0; i != size; ++i)
        {
            if (m_healths[i] == 0)
                continue;

			Robot robot = { i, positions[i], m_healths[i], directions[i] };
            
			if (robot.dir == 'R')
				processRobot(robot, R, L);
			else
				processRobot(robot, L, R);
        }

        vector<int> resulting_hp;
        for (int i = 0; i != size; ++i)
        {
			if(m_healths[i])
				resulting_hp.emplace_back(m_healths[i]);
        }

        return resulting_hp;
    }

	void processRobot(const Robot& robot, stack<Robot>& robot_stack, stack<Robot>& other_stack)
	{
		if (other_stack.empty())
		{
			robot_stack.push(robot);
		}
		else
		{
			const auto& other_robot = other_stack.top();

			if (!willCollide(robot, other_robot))
				return;

			// Other wins, we keep the other one and do not add this one
			if (robot.hp < other_robot.hp)
			{
				m_healths[robot.index] = 0;
				--m_healths[other_robot.index];
			}
			// This wins and keeps on going with one less hp
			else if (robot.hp > other_robot.hp)
			{
				--m_healths[robot.index];
				m_healths[other_robot.index] = 0;
				robot_stack.push(robot);
			}
			// Both die, we pop the other one and we do not add this one
			else
			{
				m_healths[robot.index] = 0;
				m_healths[other_robot.index] = 0;
				other_stack.pop();
			}
		}
	}

	bool willCollide(const Robot& a, const Robot& b) const noexcept
	{
		// We will assume this are has been tested for having different directions at the call site
		return (a.dir == 'L' && a.pos > b.pos) || (a.dir == 'R' && a.pos < b.pos);
	}

	vector<int> m_healths;
	stack<Robot> R;
	stack<Robot> L;
};

//vector<int> positions = {1, 2, 5, 6};
//vector<int> healths = {10, 10, 11, 11};
//string directions = "RLRL";

//vector<int> positions = { 3, 5, 2, 6 };
//vector<int> healths = { 10, 10, 15, 12 };
//string directions = "RLRL";

//vector<int> positions = { 13, 3 };
//vector<int> healths = { 17, 2 };
//string directions = "LR";

vector<int> positions = { 3, 47 };
vector<int> healths = { 46, 26 };
string directions = "LR";

int main()
{
    auto result = Solution().survivedRobotsHealths(positions, healths, directions);

    for (auto hp : result)
        std::cout << hp << ' ';
    std::cout << std::endl;
}
