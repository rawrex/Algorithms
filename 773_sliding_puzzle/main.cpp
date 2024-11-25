#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <unordered_set>

using namespace std;

struct Solution
{
    using board_t = vector<vector<int>>;
    using pos_t = pair<size_t, size_t>;

    int slidingPuzzle(board_t& root)
    {
        unordered_set<string> processed; // Use string to represent the board state
        queue<board_t> q;
        q.push(root);
        processed.insert(serialize(root));

        int moves = 0;
        while (!q.empty())
        {
            size_t size = q.size();
            for (size_t i = 0; i < size; ++i)
            {
                board_t current = q.front();
                q.pop();

                if (isTarget(current))
                    return moves;

                for (const auto& next : possibleMoves(current))
                {
                    string serialized = serialize(next);
                    if (processed.emplace(serialized).second)
                        q.push(next);
                }
            }
            ++moves;
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
        vector<board_t> possible;
        const auto& [row, col] = findStart(board);

        const vector<pos_t> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        for (const auto& [dir_row, dir_col] : directions)
        {
            size_t next_row = row + dir_row;
            size_t next_col = col + dir_col;
            if (next_row < rows && next_col < cols)
            {
                board_t next = board;
                swap(next[row][col], next[next_row][next_col]);
                possible.emplace_back(next);
            }
        }

        return possible;
    }

    pos_t findStart(const board_t& board)
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

    inline string serialize(const board_t& board)
    {
        return to_string(board[0][0]) + to_string(board[0][1]) + to_string(board[0][2]) + to_string(board[1][0]) + to_string(board[1][1]) + to_string(board[1][2]);
    }

    const static constexpr size_t rows = 2;
    const static constexpr size_t cols = 3;
};


int main()
{

}