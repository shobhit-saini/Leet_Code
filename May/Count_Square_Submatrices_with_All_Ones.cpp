/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

*/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int row_size = matrix.size(), col_size = matrix[0].size();
        int dp[row_size+1][col_size+1], i, j, res = 0;
        for( i = 0; i <= row_size; i++ )
        {
            dp[i][0] = 0;
        }
        for( j = 0; j <= col_size; j++ )
        {
            dp[0][j] = 0;
        }
        for( i = 1; i <= row_size; i++ )
        {
            for( j = 1; j <= col_size; j++ )
            {
                if( matrix[i-1][j-1] == 0 )
                    dp[i][j] = 0;
                else
                    dp[i][j] = min( dp[i-1][j], min( dp[i][j-1], dp[i-1][j-1] ) ) + 1;
                res += dp[i][j];
            }
        }
        return res;
    }
};
