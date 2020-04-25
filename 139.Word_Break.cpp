/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int i , j , size1 = s.size() , size2 = wordDict.size();
        if( size2 == 0 )
            return false ;
        string word ;
        vector<bool>dp(size1 + 1 , false) ;
        dp[0] = true ;
        map< string , int >mp ;
        for( i = 0 ; i < size2 ; i++ )
        {
            mp[wordDict[i]] = 1 ;
        }
        
        for( i = 1 ; i <= size1 ; i++ )
        {
            for( j = i - 1 ; j >= 0 ; j-- )
            {
                if( dp[j] == true )
                {
                    word = s.substr( j , i - j ) ;
                    if( mp.find( word ) != mp.end() )
                    {
                        dp[i] = true ;
                        break ;
                    }
                }
            }
        }
        return dp[size1] ;
    }
};
