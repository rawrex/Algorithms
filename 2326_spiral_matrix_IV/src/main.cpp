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
         // Initialize the matrix with -1
         vector<vector<int>> result(m, vector<int>(n, -1));

         // Set up initial indices and boundaries
         m_rows = m;
         m_cols = n;

         m_top_boundary = 0;
         m_bottom_boundary = m - 1;
         m_left_boundary = 0;
         m_right_boundary = n - 1;

         while (node)
         {
             // Fill the current cell
             result[m_row_index][m_col_index] = node->val;
             node = node->next;

             // Update the indices for the next cell
             updateIndices();
         }

         return result;
     }

 private:
     void updateIndices()
     {
         switch (m_direction)
		 {
			 // We are moving from left to right
			 case 0:
			 {
				 if (m_col_index + 1 <= m_right_boundary)
				 {
					 ++m_col_index;
				 }
				 else
				 {
					 ++m_row_index;
					 ++m_top_boundary;
					 m_direction = 1; // Change direction to top-to-bottom
				 }
				 break;
			 }

			 // We are moving from top to bottom
			 case 1:
			 {
				 if (m_row_index + 1 <= m_bottom_boundary)
				 {
					 ++m_row_index;
				 }
				 else
				 {
					 --m_col_index;
					 --m_right_boundary;

					 // Change direction to right-to-left
					 m_direction = 2; 
				 }
				 break;
			 }

			 // We are moving from right to left
			 case 2:
			 {
				 if (m_col_index - 1 >= m_left_boundary)
				 {
					 --m_col_index;
				 }
				 else
				 {
					 --m_row_index;
					 --m_bottom_boundary;

					 // Change direction to bottom-to-top
					 m_direction = 3; 
				 }
				 break;
			 }

			 // We are moving from bottom to top
			 case 3:
			 {
				 if (m_row_index - 1 >= m_top_boundary)
				 {
					 --m_row_index;
				 }
				 else
				 {
					 ++m_col_index;
					 ++m_left_boundary;

					 // Change direction to left-to-right
					 m_direction = 0; 
				 }
				 break;
			 }
         }
     }

     int m_rows = 0;
     int m_cols = 0;

     int m_row_index = 0;
     int m_col_index = 0;

     // 0 left-to-right, 1 top-to-bottom, 2 right-to-left, 3 bottom-to-top
     int m_direction = 0;

     // Boundaries for the matrix
     int m_top_boundary = 0;
     int m_bottom_boundary = 0;
     int m_left_boundary = 0;
     int m_right_boundary = 0;
 };


int main()
{

}