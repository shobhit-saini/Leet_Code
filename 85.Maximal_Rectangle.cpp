/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
*/
class Solution {
public:
    int fun_area(vector<int>&heights)
    {
        stack<int> s ;
        int area = 0 , top = -1 , i = 0 , max = 0 , val , size = heights.size();
        if( size == 0 )
            return 0 ;
        s.push(i) ;
        i++ ;
        while( !s.empty() )
        {
            if( i < size &&  heights[i] >= heights[s.top()] )
            {
                s.push(i) ;
                i++ ;
            }
            else
            {
                val = s.top() ;
                s.pop() ;
                if( s.empty() )
                {
                    area = heights[val] * i ;
                    if( i < size )
                    {
                        s.push(i) ;
                        i++ ;
                    }
                }
                else
                    area = heights[val] * (i - s.top() - 1) ;
                if( max < area )
                    max = area ;
            }
        }
        return max ;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if( matrix.size() == 0 )
            return 0 ;
        int row_size = matrix.size() , col_size = matrix[0].size() , i , j , max = 0 , area ;
        vector<int> dp(col_size) ; 
        for( i = 0 ; i < row_size ; i++ )
        {
            for( j = 0 ; j < col_size ; j++ )
            {
                if( i == 0 )
                    dp[j] = matrix[i][j] - '0' ;
                else
                {
                    if( matrix[i][j] == '0' )
                        dp[j] = 0 ;
                    else
                        dp[j] += 1 ;
                }
            }
            area = fun_area(dp) ;
            if(max < area)
                max = area ;
        }
        return max ;
    }
};
