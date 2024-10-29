#include <vector>

using namespace std;

struct Solution
{
    using matrix = vector<vector<int>>;

    struct Move
    {
        size_t row = 0;
        size_t col = 0;
    };

    int maxMoves(const matrix& grid)
    {
        grid_ptr = &grid;
        rows = grid.size();
        cols = grid[0].size();

        int max_moves = std::numeric_limits<int>::min();

        for (int row = 0; row != grid.size(); ++row)
            max_moves = std::max(max_moves, dfs(Move(row, 0)));

        return max_moves - 1;
    }

private:
	int dfs(const Move& move)
	{
        if (auto moves = possibleMovesFrom(move); !moves.empty())
        {
            int max_found = std::numeric_limits<int>::min();
            for (const auto& move : moves)
                max_found = std::max(max_found, dfs(move));

            return max_found + 1;
        }
        else
        {
            return 1;
        }
	}

    vector<Move> possibleMovesFrom(const Move& move)
    {
        vector<Move> moves;
        auto row = move.row;
        auto col = move.col;

        if (row == rows)
            return {};

        if (col == cols - 1)
            return {};

        auto value = (*grid_ptr)[row][col];
        ++col;

		if (row && (value < (*grid_ptr)[row - 1][col]))
			moves.emplace_back(row - 1, col);

        if ((row + 1 < rows) && (value < (*grid_ptr)[row + 1][col]))
			moves.emplace_back(row + 1, col);

        if (value < (*grid_ptr)[row][col])
			moves.emplace_back(row, col);

        return moves;
    }

    const matrix* grid_ptr = nullptr;
    size_t rows = 0;
    size_t cols = 0;
};

int main()
{
    Solution().maxMoves({ {2,4,3,5},{5,4,9,3},{3,4,2,11},{10,9,13,15} });
}