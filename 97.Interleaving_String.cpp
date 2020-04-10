/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
    int size1 = s1.size() , size2 = s2.size() , size3 = s3.size() , i , j , dp[size1 + 1][size2 + 1] , k ;
        if( size1 == 0 && size2 == 0 && size3 == 0 )
            return true ;
        if( (size1 + size2) != size3 )
            return false ;
        dp[0][0] = true;
        for( i = 1 ; i <= size1 ; i++ )
        {
            if( s3[i - 1] == s1[i - 1] )
                dp[i][0] = dp[i - 1][0] ;
            else
                dp[i][0] = false ;
        }
        for( i = 1 ; i <= size2 ; i++ )
        {
            if( s3[i - 1] == s2[i - 1] )
                dp[0][i] = dp[0][i - 1] ;
            else
                dp[0][i] = false ;
        }
        for( i = 1 ; i <= size1 ; i++ )
        {
            k = i ;
            for( j = 1 ; j <= size2 ; j++ )
            {
                
                if( s1[i - 1] == s3[k] && s2[j - 1] == s3[k] )
                    dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]) ; 
                else if( s1[i - 1] == s3[k] )
                    dp[i][j] = dp[i - 1][j];
                else if( s2[j - 1] == s3[k] )
                    dp[i][j] = dp[i][j - 1];
                else
                    dp[i][j] = false ;
                k++; 
            }
        }
        return dp[size1][size2] ;
    }
};
