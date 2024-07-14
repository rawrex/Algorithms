#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
    struct Robot
    {
        Robot(int pos, int hp, const string& dir) : m_position(pos), m_hp(hp), m_increment(dir == "R" ? 1 : -1) 
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

        int hp() const noexcept
        {
            return m_hp;
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
        int m_position = 0;
        int m_hp = 0;
        int m_increment = 0;
    };

    struct Scene
    {
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
            position2robot.clear();
        }

        void collide(Robot& a, Robot& b)
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

        list<Robot> m_robots;
    };

public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) 
    {
        return first(positions, healths, directions);
    }

private:
    vector<int> first(vector<int>& positions, vector<int>& healths, const string& directions)
    {

        return {};
    }
};

int main()
{

}
