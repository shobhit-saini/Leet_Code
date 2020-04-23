/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int size1 = s.size() , size2 = t.size() , i , ht1[26] , ht2[26];
        for( i = 0 ; i < 26 ; i++ )
            ht1[i] = 0 ;
        for( i = 0 ; i < size1 ; i++ )
            ht1[s[i]% 26] += 1;
        
        for( i = 0 ; i < size2 ; i++ )
            ht1[t[i]% 26] -= 1 ;
        
        for( i = 0 ; i < 26 ; i++ )
            if( ht1[i] != 0 )
                return false ;
        return true ;
    }
};
