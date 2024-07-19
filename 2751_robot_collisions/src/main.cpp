#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) 
    {
        m_size = positions.size();
        return stackSolution(positions, healths, directions);
    }

private:
    vector<int> stackSolution(vector<int>& positions, vector<int>& healths, const string& directions) const
    {
		vector<int> indices_sorted_by_position;
        for (int i = 0; i != m_size; ++i)
			indices_sorted_by_position.emplace_back(i);

		std::sort(std::begin(indices_sorted_by_position), std::end(indices_sorted_by_position), [&positions](int a, int b) { return positions[a] < positions[b]; });

		stack<int> indices_stack_R;
		for (int index : indices_sorted_by_position)
		{
			if (directions[index] == 'R')
			{
				indices_stack_R.push(index);
				continue;
			}

			int& other_robot_hp = healths[index];
			while (!indices_stack_R.empty() && other_robot_hp > 0)
			{
				int this_robot_index = indices_stack_R.top();

				if (healths[this_robot_index] < other_robot_hp)
				{
					--other_robot_hp;

					healths[this_robot_index] = 0;
					indices_stack_R.pop();
				}
				else if (healths[this_robot_index] > other_robot_hp)
				{
					other_robot_hp = 0;

					--healths[this_robot_index];
				}
				else
				{
					other_robot_hp = 0;

					healths[this_robot_index] = 0;
					indices_stack_R.pop();
				}
			}
		}

        vector<int> resulting_hp;
        for (int i = 0; i != m_size; ++i)
        {
			if(healths[i])
				resulting_hp.emplace_back(healths[i]);
        }

        return resulting_hp;
    }

	std::vector<int>::size_type m_size = 0;
};

//vector<int> positions = {1, 2, 5, 6};
//vector<int> healths = {10, 10, 11, 11};
//string directions = "RLRL";

vector<int> positions = { 3, 5, 2, 6 };
vector<int> healths = { 10, 10, 15, 12 };
string directions = "RLRL";

//vector<int> positions = { 13, 3 };
//vector<int> healths = { 17, 2 };
//string directions = "LR";

//vector<int> positions = { 3, 47 };
//vector<int> healths = { 46, 26 };
//string directions = "LR";

//vector<int> positions = { 42,3,46,2 };
//vector<int> healths = { 13,8,34,37 };
//string directions = "LRLR";

int main()
{
    auto result = Solution().survivedRobotsHealths(positions, healths, directions);

    for (auto hp : result)
        std::cout << hp << ' ';
    std::cout << std::endl;
}
