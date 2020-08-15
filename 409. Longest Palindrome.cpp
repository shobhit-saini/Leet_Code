/*
Link:https://leetcode.com/problems/longest-palindrome/
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/
class Solution {
public:
    int longestPalindrome(string s) {
        
        int i, size_s = s.size(), e, o, max = INT_MIN, count = 0;
        map<int, int>mp;
        for(i = 0; i < size_s; i++)
        {
            mp[s[i]]++;
        }
        
        map<int, int>::iterator itr;
        int flag = 0;
        for(itr = mp.begin(); itr != mp.end(); itr++)
        {
            if(itr->second%2 == 0)
            {
                count += itr->second;
            }
            else
            {
                count += (itr->second-1);
                flag = 1;
            }
        }
        if(flag == 1)
        {
            return count+1;
        }
        else
        {
            return count;
        }
    }
};
