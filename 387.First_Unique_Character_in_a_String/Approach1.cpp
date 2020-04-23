/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/
class Solution {
public:
    int firstUniqChar(string s) {
        
        map<char , int> mp ;
        int size = s.size() , i , flag = 0 , min = INT_MAX ;
        char ch ;
        for( i = 0 ; i < size ; i++ )
        {
            mp[s[i]] += 1 ; 
        }
        
        for( i = 0 ; i < size ; i++ )
        {
            if( mp[s[i]] == 1 )
            {
                flag = 1 ;
                if( min > i )
                    min = i ;
            }
        }
        if( flag == 1 )
            return min ;
 
        return -1 ;
    }
};
