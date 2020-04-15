/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?



An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        long long dp[obstacleGrid.size()][obstacleGrid[0].size()] , i , j ;
        
        for( i = 0 ; i < obstacleGrid[0].size() ; i++ )
        {
            if( obstacleGrid[0][i] == 1 )
                dp[0][i] = 0 ;
            else 
            {
                if( i == 0 )
                    dp[0][i] = 1 ;
                else
                    dp[0][i]  = dp[0][i - 1] ;
            }
        }
        if( obstacleGrid.size() == 1 )
            return dp[0][i - 1] ;
        for( j = 1 ; j < obstacleGrid.size() ; j++ )
        {
            if( obstacleGrid[j][0] == 1 )
                dp[j][0] = 0 ;
            else
                dp[j][0] = dp[j - 1][0] ;
        }
        if( obstacleGrid.size() > 1  )
        {
            for( i = 1 ; i < obstacleGrid.size() ; i++ )
            {
                for( j = 1 ; j < obstacleGrid[0].size() ; j++ )
                {
                    if( obstacleGrid[i][j] == 1 )
                        dp[i][j] = 0 ;
                    else
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] ;
                }
            }
        }
        return dp[i - 1][j - 1] ;
    }
};
