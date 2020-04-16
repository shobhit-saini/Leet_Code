/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        if( grid.size() == 0 )
            return 0 ;
        int row_size = grid.size() , col_size = grid[0].size() , i , j , dp[row_size][col_size] ;
        for( i = 0 ; i < row_size ; i++ )
        {
            for( j = 0 ; j < col_size ; j++ )
            {
                if( i == 0 && j == 0 )
                    dp[i][j] = grid[i][j] ;
                else if( i == 0 )
                    dp[i][j]  = dp[i][j - 1] + grid[i][j] ;
                else if( j == 0 )
                    dp[i][j] = dp[i - 1][j] + grid[i][j] ;
                else
                {
                    dp[i][j] = min( dp[i - 1][j] , dp[i][j - 1] ) + grid[i][j] ;
                }
                    
            }
        }
        return dp[i - 1][j - 1] ;
    }
};
