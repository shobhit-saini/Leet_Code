/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/
class Solution {
public:
    bool wordsearch( vector<vector<char>>& board, string&word, int row, int col, int k )
    {
        char temp;
        if( k == word.size() )
            return true;
        if( row > 0 && row <  board.size() && board[row-1][col] == word[k] )
        {
            temp = board[row-1][col];
            board[row-1][col] = '.';
            if( wordsearch( board, word, row-1, col, k+1 ) )
                return true;
            board[row-1][col] = temp;
            
        }
        if( row >= 0 && row < board.size()-1 && board[row+1][col] == word[k] )
        {
            temp = board[row+1][col];
            board[row+1][col] = '.';
            if( wordsearch( board, word, row+1, col, k+1 ) )
                return true;
            board[row+1][col] = temp;
        }
        if( col > 0 && col < board[0].size() && board[row][col-1] == word[k] )
        {
            temp = board[row][col-1];
            board[row][col-1] = '.';
            if( wordsearch( board, word, row, col-1, k+1 ) )
                return true;
            board[row][col-1] = temp;
        }
        if( col >= 0 && col < board[0].size()-1 && board[row][col+1] == word[k] )
        {
            temp = board[row][col+1];
            board[row][col+1] = '.';
            if( wordsearch( board, word, row, col+1, k+1 ) )
                return true;
            board[row][col+1] = temp;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int i, j;
        char temp;
        for( i = 0; i < board.size(); i++ )
        {
            for( j = 0; j < board[i].size(); j++ )
            {
                if( board[i][j] == word[0] )
                {
                    temp = board[i][j];
                    board[i][j] = '.';
                    if(wordsearch( board, word, i, j, 1 ))
                        return true;
                    board[i][j] = temp;
                }
            }
        }
        return false;
    }
};
