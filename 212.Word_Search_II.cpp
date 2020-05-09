/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 

Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.

*/
class Solution {
public:
    bool wordsearch( vector<vector<char>>& board, string& word, int row, int col, int k )
    {
        char temp;
        if( k == word.size() )
        {
            return true;
        }
        if( row > 0 && row <  board.size() && board[row-1][col] == word[k] )
        {
            temp = board[row-1][col];
            board[row-1][col] = '.';
            if( wordsearch( board, word, row-1, col, k+1 ) )
            {
                board[row-1][col] = temp;
                return true;
            }
            board[row-1][col] = temp;
            
        }
        if( row >= 0 && row < board.size()-1 && board[row+1][col] == word[k] )
        {
            temp = board[row+1][col];
            board[row+1][col] = '.';
            if( wordsearch( board, word, row+1, col, k+1 ) )
            {
                board[row+1][col] = temp;
                return true;
            }
            board[row+1][col] = temp;
        }
        if( col > 0 && col < board[0].size() && board[row][col-1] == word[k] )
        {
            temp = board[row][col-1];
            board[row][col-1] = '.';
            if( wordsearch( board, word, row, col-1, k+1 ) )
            {
                board[row][col-1] = temp;
                return true;
            }
            board[row][col-1] = temp;
        }
        if( col >= 0 && col < board[0].size()-1 && board[row][col+1] == word[k] )
        {
            temp = board[row][col+1];
            board[row][col+1] = '.';
            if( wordsearch( board, word, row, col+1, k+1 ) )
            {
                board[row][col+1] = temp;
                return true;
            }
            board[row][col+1] = temp;
        }
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       
        vector<string>output;
        int flag = 0, k, i, j;
        char temp;
        for( k = 0; k < words.size(); k++ )
        {
            flag = 0;
            for( i = 0; i < board.size(); i++ )
            {
                for( j = 0; j < board[0].size(); j++ )
                {
                    if( words[k][0] == board[i][j]  )
                    {
                        temp = board[i][j];
                        board[i][j] = '.';
                        if( wordsearch( board, words[k], i, j, 1 ) )
                        {
                            output.push_back(words[k]);
                            board[i][j] = temp;
                            flag = 1;
                            break;
                        }
                        board[i][j] = temp;
                    }
                }
                if( flag == 1 )
                        break;
            }
        }
        return output;
    }
};
