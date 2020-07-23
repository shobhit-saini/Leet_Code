/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if( matrix.size() == 0 )
            return false;
        int row_size = matrix.size(), col_size = matrix[0].size(), low = 0, high = col_size*row_size - 1;
        int m = col_size;
        while( low <= high )
        {
            int mid = ( low + high ) / 2;
            if( matrix[mid/m][mid%m] == target )
                return true;
            else if( matrix[mid/m][mid%m] < target )
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};
