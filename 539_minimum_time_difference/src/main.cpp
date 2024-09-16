#include <chrono>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Solution
{
    int findMinDifference(const vector<string>& points)
    {
		vector<int> minutes;
		minutes.reserve(points.size());

		for (const auto& point : points)
			minutes.emplace_back(str2minute(point));

		std::sort(std::begin(minutes), std::end(minutes));

		minutes.emplace_back(*minutes.cbegin() + 24 * 60);

		int minimum = std::numeric_limits<int>::max();
		for (int i = 1; i < minutes.size(); ++i)
			minimum = std::min(minimum, minutes[i] - minutes[i - 1]);

		return minimum;
    }

private:
	int str2minute(const string& time)
	{
		int hours = std::stoi(string{ std::begin(time), std::begin(time) + 2 }) * 60;
		int minutes = std::stoi(string{ std::begin(time) + 3, std::end(time) });

		return hours + minutes;
	}
};

int main()
{
	Solution().findMinDifference({ "23:59", "00:01" });
}