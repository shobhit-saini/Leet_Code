/*
Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

Example:

Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.


The above image represents the elevation map [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.

 



After the rain, water is trapped between the blocks. The total volume of water trapped is 4.

 

Constraints:

1 <= m, n <= 110
0 <= heightMap[i][j] <= 20000
*/
class Solution {
public:
    struct cell
    {
        int row; int col; int height;
        cell( int r, int c, int h )
        {
            row = r; col = c; height = h;
        }
        bool operator<(const cell& cell2)const{
            return height > cell2.height;
        }
    };
    int trapRainWater(vector<vector<int>>& heightMap) {
      
        priority_queue<cell>pq;
        int m = heightMap.size(), n = heightMap[0].size(), i, j, res = 0;
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        for(i = 0; i < m; i++)
        {
            pq.push(cell(i, 0, heightMap[i][0]));
            visited[i][0] = true;
            pq.push(cell(i, n-1, heightMap[i][n-1]));
            visited[i][n-1] = true;
        }
        
        for(j = 0; j < n; j++)
        {
            pq.push(cell(0, j, heightMap[0][j]));
            visited[0][j] = true;
            pq.push(cell(m-1, j, heightMap[m-1][j]));
            visited[m-1][j] = true;
        }
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while( !pq.empty() )
        {
            auto temp = pq.top();
            pq.pop();
            for( i = 0; i < 4; i++ )
            {
                int nx = temp.row + dx[i];
                int ny = temp.col + dy[i];
                if( valid(nx, ny, m, n) && !visited[nx][ny] )
                {
                    res += max(0, temp.height - heightMap[nx][ny]);
                    pq.push(cell(nx, ny, max(temp.height, heightMap[nx][ny])));
                    visited[nx][ny] = true;
                }
            }
        }
        return res;
    }
    
    bool valid(int nx, int ny, int m, int n)
    {
        return nx >= 0 && ny >= 0 && nx < m  && ny < n;
    }
};
