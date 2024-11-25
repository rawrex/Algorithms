#include <array>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <unordered_set>

using namespace std;

struct Solution
{
    using board_t = array<array<int, 3>, 2>;
    using pos_t = pair<size_t, size_t>;

    int slidingPuzzle(vector<vector<int>>& root)
    {
        board_t initialBoard = convertToArray(root);

        unordered_set<string> processed;
        queue<board_t> q;
        q.push(initialBoard);
        processed.insert(serialize(initialBoard));

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
        { {
            {{1, 2, 3}},
            {{4, 5, 0}}
        } };
        return board == target;
    }

    vector<board_t> possibleMoves(const board_t& board)
    {
        vector<board_t> possible;
        auto [row, col] = findStart(board);

        const vector<pos_t> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        for (const auto& [dr, dc] : directions)
        {
            size_t newRow = row + dr;
            size_t newCol = col + dc;
            if (newRow < rows && newCol < cols)
            {
                board_t next = board;
                swap(next[row][col], next[newRow][newCol]);
                possible.push_back(next);
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

    string serialize(const board_t& board)
    {
        string s;
        for (const auto& row : board)
            for (int cell : row)
                s += to_string(cell);
        return s;
    }

    board_t convertToArray(const vector<vector<int>>& vec)
    {
        board_t arr;
        for (size_t row = 0; row < rows; ++row)
            for (size_t col = 0; col < cols; ++col)
                arr[row][col] = vec[row][col];
        return arr;
    }

    const static constexpr size_t rows = 2;
    const static constexpr size_t cols = 3;
};

int main()
{

}