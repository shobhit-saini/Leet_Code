/*
Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 10^5.
All elements in the matrix are distinct.
*/
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        int i , j , row_index , col_index , min , max , k ;
        vector<int> v ;
        for( i = 0 ; i < matrix.size() ; i++ )
        {
            min = matrix[i][0] ;
            row_index = i ;
            col_index = 0 ;
            for( j = 1 ; j < matrix[0].size() ; j++ )
            {
                if( min > matrix[i][j] )
                {
                    min = matrix[i][j] ;
                    col_index = j ;
                }
            }
            max = min ;
            for( k = 0 ; k < matrix.size() ; k++ )
            {
                if( max < matrix[k][col_index] )
                    max = matrix[k][col_index] ;
            }
            if( max == min )
                v.push_back(max) ;
        }
        return v ;
    }
};
