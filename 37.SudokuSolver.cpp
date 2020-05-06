/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.


A sudoku puzzle...


...and its solution numbers marked in red.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.
*/
class Solution {
public:
    bool validate( vector<vector<char>>&board, int row, int col, char j )
    {
        int i, k, l, m;
        for( i = 0; i < 9; i++ )
        {
            if( board[row][i] == j )
                return false;
        }
        for( i = 0; i < 9; i++ )
        {
            if( board[i][col] == j )
                return false;
        }
        i = row - row%3;
        m = col - col%3;
        cout << i << m;
        for( k = i; k < (i + 3); k++ )
        {
            for( l = m; l < (m + 3); l++ )
            {
                if( board[k][l] == j )
                    return false;
            }
        }
        return true;
        
    }
    bool sudoku( vector<vector<char>>& board, int row, int col )
    {
        if( row == 9 )
            return true;
        if( col == 9 )
        {
            return sudoku( board, row+1, 0 );
        }
       if( board[row][col] != '.' )
            return sudoku( board, row, col + 1 );
        for( char j = '1'; j <= '9'; j++ )
        {
            if( validate( board, row, col, j ) )
            {
                board[row][col] = j; 
                if(sudoku( board, row,col+1 )) 
                    return true;
                board[row][col] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        
        sudoku( board, 0, 0 );
    }
};
