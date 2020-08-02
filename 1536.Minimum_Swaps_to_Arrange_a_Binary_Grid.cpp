/*
Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.

A grid is said to be valid if all the cells above the main diagonal are zeros.

Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.

The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).

 

Example 1:


Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
Output: 3
Example 2:


Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
Output: -1
Explanation: All rows are similar, swaps have no effect on the grid.
Example 3:


Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
Output: 0
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 200
grid[i][j] is 0 or 1
*/
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        
        int row_size = grid.size(), col_size = grid[0].size(), i, j, count = 0, t, res = 0;
        vector<int>temp;
        for(i = 0; i < row_size; i++)
        {
            count = 0;
            for(j = col_size-1; j >= 0; j--)
            {
                if(grid[i][j] == 0)
                    count++;
                else
                    break;
            }
            temp.push_back(count);
        }

        for(i = 0; i < row_size; i++)
        {
            int j = i;
            while(j < row_size && temp[j] < row_size-i-1)
            {
                j++;
            }
            if(j == row_size)
                return -1;
            while(j > i)
            {
                t = temp[j];
                temp[j] = temp[j-1];
                temp[j-1] = t;
                res++;
                j--;
            }
        }
        return res;
    }
};
