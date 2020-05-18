/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
 
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int size1 = s1.size(), size2 = s2.size(), i = 0, k;
        if( size1 > size2 )
            return false;
        int arr1[26] = {0}, arr2[26] = {0};
        for( i = 0; i < size1; i++ )
        {
            arr1[s1[i]-'a']++;
        }
        for( i = 0; i < size1; i++ )
        {
            arr2[s2[i]-'a']++;
        }
        for( i = 0; i < 26; i++ )
        {
            if( arr1[i] != arr2[i] )
                break;
        }
        if( i == 26 )
            return true;
        int j = 0;
        for( k = size1; k < size2; k++ )
        {
            arr2[s2[j]-'a']--;
            arr2[s2[k]-'a']++;
            for( i = 0; i < 26; i++ )
            {
                if( arr1[i] != arr2[i] )
                    break;
            }
            if( i == 26 )
                return true;
            j++;
        }
        return false;
    }
};
