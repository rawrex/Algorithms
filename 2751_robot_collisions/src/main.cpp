#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Robot
{
	Robot(int i, int pos, int hp, char dir) : m_original_index(i), m_position(pos), m_hp(hp), m_increment(dir == 'R' ? 1 : -1)
	{

	}

	int onTick()
	{
		return m_position += m_increment;
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

class Solution 
{
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
            unordered_map<int, Robot*> position2robot;

            for(auto& current_robot : m_robots)
            {
                if(current_robot.isDead())
                    continue;

                if(!position2robot.emplace(current_robot.onTick(), &current_robot).second)
                {
                    auto& other_robot_ptr = position2robot[current_robot.position()];
                    collide(current_robot, *other_robot_ptr);
                }
            }
        }

        void collide(Robot& a, Robot& b) const noexcept
        {
            if(a.hp() == b.hp())
            {
                a.kill();
                b.kill();
                return;
            }
            if(a.hp() < b.hp())
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

            for(const auto& robot : m_robots)
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
                if(!robot.isDead())
                    alive.emplace_back(robot);

            std::sort(alive.begin(), alive.end(), [](const auto& a, const auto& b) { return a.originalPosition() < b.originalPosition(); });

            std::vector<int> result;
            for (const auto& r : alive)
                result.emplace_back(r.hp());

            return result;
        }

        vector<Robot> m_robots;
    };

public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) 
    {
        Scene scene(positions, healths, directions);

        while (!scene.done())
            scene.tick();

        return scene.finish();
    }
};

struct Solution2
{
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, const string& directions) 
    {
        auto size = static_cast<int>(positions.size());

        list<int> moving_left_indices; 
        list<int> moving_right_indices; 

        for(int i = 0; i != size; ++i)
        {
            if(directions[i] == 'R')
                moving_right_indices.push_back(i);
            else
                moving_left_indices.push_back(i);
        }

        while(!done())
        {

        }

        return {};
    }

    bool done() 
    {
       // left is empty 
       // right is empty 
       // positions are safe
    }
};


struct Solution3
{
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, const string& directions) 
    {
        auto total_size = static_cast<int>(positions.size());

        for(int i = 0; i != total_size; ++i)
        {
            if(directions[i] == 'L')
                m_left.emplace_back(i, positions[i], healths[i], directions[i]);
            else
                m_right.emplace_back(i, positions[i], healths[i], directions[i]);
        }

        std::sort(m_left.begin(), m_left.end(), [](const auto& a, const auto& b) { return a.position() < b.position(); });
        std::sort(m_right.begin(), m_right.end(), [](const auto& a, const auto& b) { return a.position() < b.position(); });

        auto min_size = std::min(m_left.size(), m_right.size());
        
        while(!done())
        {
            
        }
    }

    bool done() 
    {
       // left is empty 
       // right is empty 
       // positions are safe
    }
private:
    std::vector<Robot> m_left;
    std::vector<Robot> m_right;
};

int main()
{

}
