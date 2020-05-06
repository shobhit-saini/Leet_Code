/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
class Solution {
public:
    bool validate( vector<string>&res, int row, int col, int n )
    {
        int i, j;
        for( i = row; i >= 0; i-- )
        {
            if( res[i][col] == 'Q' )
                return false;
        }
        for( i = row-1, j = col-1; i >= 0 && j >=0; i--, j-- )
        {
            if( res[i][j] == 'Q' )
                return false;
        }
        for( i = row, j = col; i >=0 && j < n; i--, j++ )
        {
            if( res[i][j] == 'Q' )
                return false;
        }
        return true;
    }
    void queen( vector<string>&res, int&count, int row, int n )
    {
        if( row == n )
        {
            count++;
            return;
        }
        for( int col = 0; col < n; col++ )
        {
            if( validate( res, row, col, n ) )
            {
                res[row][col] = 'Q';
                queen( res, count, row+1, n );
                res[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        
        vector<string>res(n, string(n, '.'));
        int count = 0;
        queen( res, count, 0, n );
        return count;
    }
};
