/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i , size = s.size() , start = 0 , max = INT_MIN;
        if( size == 0 )
            return 0 ;
        map<char , int> mp ;
        for( i = 0 ; i < size ; i++ )
        {
            if( mp.find(s[i]) == mp.end() )
            {
                mp[s[i]] = 1 ;
                if( max < (int)mp.size() )
                    max = mp.size();
            }
            else
            {
                while(s[start] != s[i] )
                {
                    mp.erase(s[start]) ;
                    start++ ;
                }
                start++;
            }              
        }
        
       return max ;     
    }
        
};
