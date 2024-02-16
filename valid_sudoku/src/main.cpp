#include <vector>
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

void print(char c)
{
    std::cout << c << ' ';
}

bool flat(const vector<vector<char>>& input) noexcept
{
    unordered_map<size_t, unordered_set<char>> tracker;

    for (size_t i = 0; i != 81; ++i)
    {
        auto column = static_cast<size_t>(i % 9);
        auto row = static_cast<size_t>(i / 9);

        auto box = (column / 3) + (row / 3);

        auto& item = input[row][column];

        // in the end the total sum should be zero (?)
        std::cout << "box: " << box << std::endl;
        
        // print(input[row][column]);
    }

    return true;
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << flat(good) << std::endl; 
    // std::cout << flat(bad) << std::endl;
}
