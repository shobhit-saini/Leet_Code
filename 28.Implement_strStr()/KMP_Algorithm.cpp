class Solution {
public:
    int strStr(string haystack, string needle) {
       
        int size1 = haystack.size() , size2 = needle.size() , i , j = 0 , k ;
        if( size1 < size2 )
            return -1 ;
        if( size2 == 0 )
            return 0 ;
        int pss[size2];
        pss[0] = 0;
        for( i = 1; i < size2; )
        {
            if( needle[j] == needle[i] )
            {
                pss[i] = j+1;
                j++;
                i++;
            }
            else
            {
                if( j != 0 )
                {
                    j = pss[j-1];
                }
                else
                {
                    pss[i] = 0;
                    i++;
                }
            }
        }
        
        for( i = 0, j = 0; i < size1;  )
        {
            if( haystack[i] == needle[j] )
            {
                j++;
                i++;
            }
            else
            {
                if( j != 0 )
                    j = pss[j - 1];
                else
                    i++;
            }
            if( j == size2 )
                return i-j;
        }
        return -1 ;
    }
};
