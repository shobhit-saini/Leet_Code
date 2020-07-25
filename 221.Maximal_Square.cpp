/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if( matrix.size() == 0 )
            return 0;
        int row_size = matrix.size(), col_size = matrix[0].size(), i, j, maxi = 0;
        vector<vector<int>>dp(row_size+1, vector<int>(col_size+1, 0));
        for( i = 1; i <= row_size; i++ )
        {
            for( j = 1; j <= col_size; j++ )
            {
                if( matrix[i-1][j-1] == '1' )
                {  
                    dp[i][j] = min( dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]) ) + 1;
                    if( maxi < dp[i][j] )
                        maxi = dp[i][j];
                }
            }
        }
        return maxi*maxi;
    }
};
