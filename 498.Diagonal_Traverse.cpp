/*
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

 

Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

Explanation:

 

Note:

The total number of elements of the given matrix will not exceed 10,000.
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        
        vector<int>res;
        if( matrix.size() == 0 )
            return res;
        int i, j, row_size = matrix.size(), col_size = matrix[0].size(), k;
        vector<vector<int>>v(max(2*row_size-1, 2*col_size-1));
        for( i = 0; i < row_size; i++ )
        {
            k = i;
            for( j = 0; j < col_size; j++ )
            {
                if( k % 2 == 0 )
                    v[k].insert(v[k].begin(), matrix[i][j]);
                else
                    v[k].push_back(matrix[i][j]);
                k++;
            }
        }
        for( i = 0; i < v.size(); i++ )
        {
            for( j = 0; j < v[i].size(); j++ )
            {
                res.push_back(v[i][j]);
            }
        }
        return res;
    }
};
