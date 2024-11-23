#include <queue>
#include <vector>
#include <utility>

using namespace std;

struct Solution
{
	using box_t = vector<vector<char>>;

	box_t rotateTheBox(box_t& box) 
	{
		auto rows_n = static_cast<int>(box.size());
		auto cols_n = static_cast<int>(box.back().size());

		box_t rotated(cols_n, vector<char>(rows_n, '.'));

		for (int row = 0; row < rows_n; ++row)
		{
			for (int col = cols_n - 1, obstacle = cols_n - 1; col >= 0; --col)
			{
				if (box[row][col] != '.') 
				{
					if (box[row][col] == '*')
						obstacle = col;

					rotated[obstacle--][rows_n - row - 1] = box[row][col];
				}
			}
		}
		return rotated;
	}
};

int main()
{

}