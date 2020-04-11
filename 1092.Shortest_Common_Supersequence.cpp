/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.  If multiple answers exist, you may return any of them.

(A string S is a subsequence of string T if deleting some number of characters from T (possibly 0, and the characters are chosen anywhere from T) results in the string S.)

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
 

Note:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.
*/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int size1 = str1.size() , size2 = str2.size() , i , j , dp[size1 + 1][size2 + 1] ;
        string res = "" ;
        for( i = 0 ; i <= size1 ; i++ )
        {
            for( j = 0 ; j <= size2 ; j++ )
            {
                if( i == 0 || j == 0 )
                    dp[i][j] = 0 ;
                else
                {
                    if( str1[i - 1] == str2[j - 1] )
                        dp[i][j] = dp[i - 1][j - 1] + 1 ;
                    else
                        dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1] ;
                }
            }
        }
        str1 = " " + str1 ;
        str2 = " " + str2 ;
        for( i = size1 , j = size2 ; i || j ; )
        {
            if(i>0 && j > 0 && str1[i] == str2[j]) 
            {
                res = str1[i] + res ;
                i--; j--;
            }
            else if( i > 0 && dp[i][j] == dp[i - 1][j] )
            {
                res = str1[i] + res ;
                i-- ;
            }
            else if( j > 0 && dp[i][j] == dp[i][j - 1] )
            {
                res = str2[j] + res ;
                j-- ;
            }
        }
         return res ;  
     }
};
