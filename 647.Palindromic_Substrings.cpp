/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Note:

The input string length won't exceed 1000.
*/
class Solution {
public:
    int countSubstrings(string s) {
        
        int i, s_size = s.size(), res = 0;
        for( i = 0; i < s_size; i++ )
        {
            res += check(s, i, i); // odd palindrome
            res += check(s, i, i+1); // even palindrome
        }
        return res;
    }
    
    int check(string s, int i, int j)
    {
        int count = 0;
        while( i >= 0 && j < s.size() && s[i] == s[j] )
        {
            count++;
            i--;
            j++;
        }
        return count;
    }
};
