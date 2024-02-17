#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<vector<char>> good = 
{
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
};

vector<vector<char>> bad = 
{
    {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
};

vector<vector<char>> bad_2 = 
{
    {'.', '1', '.', '5', '2', '.', '.', '.', '.'},
    { '.', '.', '.', '.', '.', '6', '4', '3', '.' },
    { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    { '5', '.', '.', '.', '.', '.', '9', '.', '.' },
    { '.', '.', '.', '.', '.', '.', '.', '5', '.' },
    { '.', '.', '.', '5', '.', '.', '.', '.', '.' },
    { '9', '.', '.', '.', '.', '3', '.', '.', '.' },
    { '.', '.', '6', '.', '.', '.', '.', '.', '.' },
    { '.', '.', '.', '.', '.', '.', '.', '.', '.' }
};

struct Position
{
	size_t m_row = -1;
	size_t m_column = -1;
	size_t m_box = -1;
};

bool operator==(const Position& a, const Position& b)
{
	return a.m_row == b.m_row || a.m_column == b.m_column || a.m_box == b.m_box;
}

bool flat(const vector<vector<char>>& input) noexcept
{
    unordered_map<char, vector<Position>> tracker;

    for (size_t i = 0; i != 81; ++i)
    {
        auto row = static_cast<size_t>(i / 9);
        auto column = static_cast<size_t>(i % 9);
        auto box = (column / 3) + (row / 3) * 3;

        auto& item = input[row][column];

        if (item == '.')
            continue;

        Position current_position{ row, column, box };
        auto& present_positions = tracker[item];

        if (present_positions.empty())
        {
            present_positions.emplace_back(current_position);
            continue;
        }

        for (const auto& present_position : present_positions)
        {
            if (current_position == present_position)
                return false;
        }
        present_positions.emplace_back(current_position);
    }

    return true;
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << flat(good) << std::endl; 
    std::cout << flat(bad) << std::endl;
    std::cout << flat(bad_2) << std::endl;
}
