/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
class Solution {
public:
    void parenthesis( int n, vector<string>& output, string s, int open, int close )
    {
        if( s.size() == 2*n )
        {
            output.push_back( s );
            return;
        }
        if( open < n )
            parenthesis( n, output, s+'(', open+1, close );
        if( close < open )
            parenthesis( n, output, s+')', open, close+1 );
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string>output;
        string s;
        parenthesis( n, output, s, 0, 0 );
        return output;
    }
};
