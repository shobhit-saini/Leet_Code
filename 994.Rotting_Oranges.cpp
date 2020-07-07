/*
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int, int>>q;
        pair<int, int>p, temp = {-1, -1}, v;
        int i, j, rows = grid.size(), cols = grid[0].size(), res = 0;
        for( i = 0; i < rows; i++ )
        {
            for( j = 0; j < cols; j++ )
            {
                if( grid[i][j] == 2 )
                {
                    q.push({i,j});
                }
            }
        }
        q.push(temp);
        while( !q.empty() )
        {
            
            if( q.front() == temp )
            {
                res++;
                if( q.size() > 1 )
                    q.push(temp);
                q.pop();
            }
            else
            {
                v = q.front();
                q.pop();
                if( grid[v.first][v.second] == 2 )
                {
                    if( v.first > 0 )
                    {
                        if(grid[v.first-1][v.second] == 1)
                        {
                            grid[v.first-1][v.second] = 2;
                            q.push({v.first-1,v.second});
                        }
                    }
                    
                    if( v.second > 0 )
                    {
                        if(grid[v.first][v.second-1] == 1)
                        {
                           grid[v.first][v.second-1] = 2;
                            q.push({v.first, v.second-1});
                        }
                    }
                    
                    if( v.first < rows-1 )
                    {
                        if( grid[v.first+1][v.second] == 1 )
                        {
                            grid[v.first+1][v.second] = 2;
                            q.push({v.first+1, v.second});
                        }
                            
                    }
                    if( v.second < cols-1 )
                    {
                        if(grid[v.first][v.second+1] == 1 )
                        {
                           grid[v.first][v.second+1] = 2;
                           q.push({v.first, v.second+1});
                        }
                    }
                            
                }
            }
        } 
        for( i = 0; i < rows; i++ )
        {
            for( j = 0; j < cols; j++ )
            {
                if( grid[i][j] == 1 )
                    return -1;
            }
        }
        return res-1;
    }
};
