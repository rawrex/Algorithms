#include <vector>

using namespace std;

 struct ListNode 
 {
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}

     int val;
     ListNode *next;
 };
 

struct Solution 
{
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* node) 
    {
        vector<vector<int>> result(m, vector<int>(n, -1));

        for (/* empty */; node; node = node->next)
        {
            updateIndices();
            result[m_col_index][m_col_index] = node->val;
        }

        return result;
    }

private:
    void updateIndices()
    {

    }

    int m_row_index = 0;
    int m_col_index = 0;
};

int main()
{

}