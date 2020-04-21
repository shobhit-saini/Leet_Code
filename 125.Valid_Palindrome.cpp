/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/
class Solution {
public:
    bool isPalindrome(string s) {
        
        int size = s.size() , i = 0 , j = size - 1 ;
        while( i <= j )
        {
            while( i < size && !isalnum(s[i]) )
                i++ ;
            while( j >= 0 && !isalnum(s[j]) )
                j-- ;
            if( i == size || j == -1 )
                return true ;
            if( tolower(s[i]) != tolower(s[j]))
                return false ;
            else
            {
                i++ ;
                j-- ;
            }
                
        }
        return true ;
    }
};
