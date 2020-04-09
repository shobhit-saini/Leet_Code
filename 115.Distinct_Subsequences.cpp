/*
Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Example 1:

Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation:

As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
Example 2:

Input: S = "babgbag", T = "bag"
Output: 5
Explanation:

As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        
        int size1 = s.size() , size2 = t.size() , i , j ;
        long dp[size2 + 1][size1 + 1];
        for( i = 0 ; i <= size1 ; i++ )
        {
            dp[0][i] = 1 ;
        }
        for( i = 1 ; i <= size2 ; i++ )
        {
            dp[i][0] = 0 ;
        }
        for( i = 1 ; i <= size2 ; i++ )
        {
            for( j = 1 ; j <= size1 ; j++ )
            {
                if( s[j - 1] == t[i - 1] )
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] ;
                else
                    dp[i][j] = dp[i][j - 1] ;
            }
        }
        return dp[size2][size1] ;
    }
};
