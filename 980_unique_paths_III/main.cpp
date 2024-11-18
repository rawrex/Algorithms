#include <vector>
#include <array>
#include <unordered_set>

using namespace std;

struct Solution
{
    using Grid = vector<vector<int>>;

    struct Cell
    {
        friend bool operator==(const Cell& a, const Cell& b) noexcept
        {
            return a.row == b.row && a.col == b.col;
        }

        std::uint64_t id() const noexcept
        {
			return static_cast<std::uint64_t>(row) * 100 + col;
        }

        int row = 0;
        int col = 0;
    };

    int uniquePathsIII(Grid& grid)
    {
        rows_n = grid.size();
        cols_n = grid.back().size();

        preprocess(grid);

        std::unordered_set<std::uint64_t> visited;
        visited.emplace(start.id());
        countWalks(start, visited, 1);

        return counter;
    }

private:
    void preprocess(Grid& grid)
    {
        for (int row = 0; row != rows_n; ++row)
        {
            for (int col = 0; col != cols_n; ++col)
            {
                Cell cell{ row, col };

                switch (grid[row][col])
                {
                case 1:
                    start = cell;
                    break;
                case 2:
                    finish = cell;
                    break;
                case -1:
                    obstacles.emplace(cell.id());
                    break;
                default:
                    break;
                }

                if (grid[row][col] != -1)
                    ++walkable_count;
            }
        }
    }

    void countWalks(const Cell& cell, std::unordered_set<std::uint64_t>& visited, int visited_count)
    {
        if (cell == finish)
        {
            if(visited_count == walkable_count)
				++counter;

            return;
        }

        std::array<Cell, 4> directions = { Cell{cell.row + 1, cell.col}, Cell{cell.row - 1, cell.col}, Cell{cell.row, cell.col + 1}, Cell{cell.row, cell.col - 1} };

        for (const auto& next : directions)
        {
            if (walkable(next) && !visited.contains(next.id()))
            {
                visited.emplace(next.id());
                countWalks(next, visited, visited_count + 1);

				// Backtrack
                visited.erase(next.id());
            }
        }
    }

    bool walkable(const Cell& cell)
    {
        return cell.row < rows_n && cell.row >= 0 && cell.col < cols_n && cell.col >= 0 && !obstacles.contains(cell.id());
    }

    int rows_n = 0;
    int cols_n = 0;
    int counter = 0;
    int walkable_count = 0;

    Cell start;
    Cell finish;
    std::unordered_set<std::uint64_t> obstacles;
};

int main()
{

}