/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
         vector<int>res;
        if( matrix.size() == 0 )
            return res;
        int p = 0, i, row_size = matrix.size(), col_size = matrix[0].size(), k = 0, l = col_size-1, m = row_size-1, n = 0;
        
        while( k <= m && n <= l )
        {
            for( i = p; i < col_size-p; i++ )
            {
                res.push_back(matrix[k][i]);
            }
            k++;

            for( i = p+1; i < row_size-p; i++ )
            {
                res.push_back(matrix[i][l]);
            }
            l--;

            if( k <= m )
            {
                for( i = col_size-2-p; i >= 0+p; i-- )
                {
                    res.push_back(matrix[m][i]);
                }
                m--;
            }

            if( n <= l )
            {
                for( i = row_size-2-p; i >= p+1; i-- )
                {
                    res.push_back(matrix[i][n]);
                }
                n++;
            }

            p++;
        }
        return res;
    }
};
