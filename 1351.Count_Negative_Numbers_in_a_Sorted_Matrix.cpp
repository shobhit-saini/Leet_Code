/*
Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 

Return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
Example 3:

Input: grid = [[1,-1],[-1,-1]]
Output: 3
Example 4:

Input: grid = [[-1]]
Output: 1
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100

*/
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
     
        int i, j, count = 0, flag = 0, tmp, row_size = grid.size(), col_size = grid[0].size(), k = col_size;
        for(i = 0; i < row_size; i++)
        {
            for(j = 0; j < k; j++)
            {
               
                if(grid[i][j] < 0)
                {
                    count += (row_size - i);
                    if(flag == 0)
                    {
                        flag = 1;
                        tmp = j;
                    }
                }
            }
            k = tmp;
            flag = 0;
        }
        return count;
    }
};
