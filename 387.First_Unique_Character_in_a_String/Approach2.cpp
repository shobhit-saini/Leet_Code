/*
class Solution {
public:
    int firstUniqChar(string s) {
        
        int ht[26] , size = s.size() , i ;
        for( i = 0 ; i < 26 ; i++ )
        {
            ht[i] = 0 ;
        }
        for( i = 0 ; i < size ; i++ )
        {
            ht[s[i]%26] += 1 ;
        }
        for( i = 0 ; i < size ; i++ )
        {
            if( ht[s[i]%26] == 1 )
                return i;
        }
        return -1 ;
    }
};
*/
