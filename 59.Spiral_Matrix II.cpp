/*
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n, vector<int>(n));
        if( n == 0 )
            return matrix;
        int p = 0, i, row_size = n, col_size = n, k = 0, l = col_size-1, m = row_size-1, q = 0, count = 1;
        
        while( k <= m && q <= l )
        {
            for( i = p; i < col_size-p; i++ )
            {
                matrix[k][i] = count;
                count++;
            }
            k++;
            
            for( i = p+1; i < row_size-p; i++ )
            {
                matrix[i][l] = count;
                count++;
            }
            l--;

            if( k <= m )
            {
                for( i = col_size-2-p; i >= 0+p; i-- )
                {
                    matrix[m][i] = count;
                    count++;
                }
                m--;
            }

            if( q <= l )
            {
                for( i = row_size-2-p; i >= p+1; i-- )
                {
                    matrix[i][q] = count;
                    count++;
                }
                q++;
            }
            p++;
        }
        return matrix;
    }
};
