/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/
class Solution {
public:
    bool validate( int row, int col, vector<string>res, int n )
    {
        int i, j;
        for( i = row; i >= 0; i-- )
        {
            if( res[i][col] == 'Q' )
                return false;
        }
        for( i = row-1, j = col-1; i >= 0 && j >= 0; i--, j-- )
        {
            if( res[i][j] == 'Q' )
                return false;
        }
        for( i = row, j = col; i >= 0 && j < n; i--, j++ )
        {
            if( res[i][j] == 'Q' )
                return false;
        }
        return true;
    }
    void queen( vector<string>&res, int n, int row, vector<vector<string>>&output )
    {
        if( row == n )
        {
            output.push_back(res);
            return;
        }
        for( int col = 0; col < n; col++ )
        {
            if( validate( row, col, res, n ) )
            {
                res[row][col] = 'Q';
                queen( res, n, row+1, output );
                res[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>>output;
        vector<string>res( n, string( n, '.' ) );
        queen( res, n, 0, output );
        return output;
    }
};
