#include <queue>
#include <vector>
#include <utility>
#include <unordered_set>

using namespace std;

struct Solution 
{
    using board_t = vector<vector<int>>;

    int slidingPuzzle(board_t& root) 
    {
        unordered_set<board_t> processed;
        queue<board_t> q;
        q.emplace(root);

        int count = 0;
        while (!q.empty())
        {
            const auto& current = q.back();
            q.pop();

            if (isTarget(current))
                return count;

            for (const auto& possible : possibleMoves(current))
            {
                if (!processed.emplace(possible).second)
                    q.push(possible);
            }
        }

        return -1;
    }

private:
    bool isTarget(const board_t& board)
    {
        const static board_t target
        {
            {1, 2, 3},
            {4, 5, 0}
        };
        return board == target;
    }

    vector<board_t> possibleMoves(const board_t& board)
    {
        // For now we do not pass the current zero position info
        vector<board_t> possible;
        const auto& [row, col] = findStart(board);

		if (row != 0 && col == 1)
        {
            possible.emplace_back(row - 1, col);
            possible.emplace_back(row, col + 1);
            possible.emplace_back(row, col - 1);
        }
        else if (row != 0 && col == 0)
        {
            possible.emplace_back(row - 1, col);
            possible.emplace_back(row, col + 1);
        }
        else if (row != 0 && col == 2)
        {
            possible.emplace_back(row - 1, col);
            possible.emplace_back(row, col - 1);
        }
		else if (row == 0 && col == 1)
        {
            possible.emplace_back(row + 1, col);
            possible.emplace_back(row, col + 1);
            possible.emplace_back(row, col - 1);
        }
        else if (row == 0 && col == 0)
        {
            possible.emplace_back(row + 1, col);
            possible.emplace_back(row, col + 1);
        }
        else if (row == 0 && col == 2)
        {
            possible.emplace_back(row + 1, col);
            possible.emplace_back(row, col - 1);
        }

        return possible;
    }

    pair<size_t, size_t> findStart(const board_t& board)
    {
        for (size_t row = 0; row < rows; ++row)
        {
            for (size_t col = 0; col < cols; ++col)
            {
                if (board[row][col] == 0)
                    return { row, col };
            }
        }
        return { 0, 0 };
    }

    const static constexpr size_t rows = 2;
    const static constexpr size_t cols = 3;
};

int main()
{

}