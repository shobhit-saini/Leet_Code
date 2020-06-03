/*
Given a square array of integers A, we want the minimum sum of a falling path through A.

A falling path starts at any element in the first row, and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.

 

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12
Explanation: 
The possible falling paths are:
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
The falling path with the smallest sum is [1,4,7], so the answer is 12.

 

Note:

1 <= A.length == A[0].length <= 100
-100 <= A[i][j] <= 100
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        
        int i, j, size = A.size(), dp[size][size];
        for( i = 0; i < size; i++ )
        {
            dp[0][i] = A[0][i];
        }
        
        for( i = 1; i < size; i++ )
        {
            for( j = 0; j < size; j++ )
            {
                if( j == 0 )
                {
                     dp[i][0] = A[i][0] + min( dp[i-1][0], dp[i-1][1] );
                }
                else if( j == size-1 )
                {
                    dp[i][size-1] = A[i][size-1] + min( dp[i-1][size-1], dp[i-1][size-2] );
                }
                else
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j+1], dp[i-1][j])) + A[i][j];
            }
        }
        int mini = INT_MAX;
        for( i = 0; i < size; i++ )
        {
            mini = min( mini, dp[size-1][i] );
        }
        return mini;
    }
};
