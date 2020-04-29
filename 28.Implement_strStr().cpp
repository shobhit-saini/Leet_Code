/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
       
        int size1 = haystack.size() , size2 = needle.size() , i , j , k ;
        
        if( size1 < size2 )
            return -1 ;
        if( size2 == 0 )
            return 0 ;
        string str = needle , str1;
        for( i = 0 ; i < size2 ; i++ )
        {
           str1.push_back(haystack[i]) ;
        }
        cout << str1 << "hj ";
        if( str1 == str )
            return 0 ;
        for( i = size2 ; i < size1 ; i++)
        {
            str1.erase(0 , 1);
            str1.push_back(haystack[i]) ;
            if( str1 == str )
                return i - size2 + 1 ;
        }
        return -1 ;
    }
};
