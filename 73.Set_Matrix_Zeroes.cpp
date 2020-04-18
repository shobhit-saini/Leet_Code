/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int row_size = matrix.size() , col_size = matrix[0].size() , i , j ;
        bool first_col = false ;
        for( i = 0 ; i < row_size ; i++ )
        {
            for( j = 0 ; j < col_size ; j++ )
            {
                if((i == 0 && j == 0 || j == 0) && matrix[i][j] == 0 )
                    first_col = true ;
                else if( matrix[i][j] == 0 )
                {
                    matrix[0][j] = 0 ;
                    matrix[i][0] = 0 ;
                }
            }
        }
        for( i = 1 ; i < row_size ; i++ )
        {
            for( j = 1 ; j < col_size ; j++ )
            {
                if( matrix[i][0] == 0 || matrix[0][j] == 0 )
                    matrix[i][j] = 0 ;
            }
        }
        
        if( matrix[0][0] == 0 )
        {
            for( i = 0 ; i < col_size ; i++ )
            {
                matrix[0][i] = 0 ;
            }
        }
        if( first_col )
        {
            for( i = 0 ; i < row_size ; i++ )
                matrix[i][0] = 0 ;
        }    
    }
};
