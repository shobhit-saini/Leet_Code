/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        
        int size1 = s.size() , size2 = p.size() , i , j ;
        bool dp[size1 + 1][size2 + 1] ;
        dp[0][0] = true ;
        for( i = 1 ; i <= size2 ; i++ )
        {
            if( p[i - 1] == '*' )
                dp[0][i] = dp[0][i - 1] ; 
            else
                dp[0][i] = false ;
        }
        for( i = 1 ; i <= size1 ; i++ )
        {
            dp[i][0] = false ;
        }
        for( i = 1 ; i <= size1 ; i++ )
        {
            for( j = 1 ; j <= size2 ; j++ )
            {
                if( p[j - 1] == '*' )
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j - 1] || dp[i - 1][j] ;
                else if( p[j - 1] == '?' || p[j - 1] == s[i - 1])
                    dp[i][j] = dp[i - 1][j - 1] ;
                else
                    dp[i][j] = false ;
            }
        }
        return dp[size1][size2] ;
    }
};
