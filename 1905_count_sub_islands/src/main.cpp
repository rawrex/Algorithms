#include <vector>
#include <iostream>

using namespace std;

template<typename T>
using matrix_type = vector<vector<T>>;

template<typename T>
using size_type = matrix_type<T>::size_type;

struct Solution 
{
    int countSubIslands(matrix_type<int>& grid1, matrix_type<int>& grid2) 
    {
        for (size_type<int> i = 0; i != grid1.size(); ++i)
        {
            // subscript warning
            for (size_type<int> j = 0; j != grid1[0].size(); ++j)
            {

            }
        }
        return 0;
    }

private:
    bool dfs(matrix_type<int>& grid1, matrix_type<int>& grid2)
    {
        
    }
};

int main()
{

}