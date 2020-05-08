/*
Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
*/
class Solution {
public:
    bool rabin(string& str, string& B, int hash1, int hash2)
    {
        int size1 = str.size(), size2 = B.size(), i, j = 0, k, l;
        int power = 1, mod = 100000;
        for( i = 0; i < size2-1; i++ )
        {
            power = (power*31)%mod;
        }
        if( hash1 == hash2 )
        {
            cout << "ds";
            for( i = 0; i < size2; i++ )
            {
                if( str[i] != B[i] )
                    break;
            }
            if( i == size2 )
                return true;
        }
        for( i = size2; i < size1; i++ )
        {
            hash2 = (((hash2 - str[i-size2]*power)*31) + str[i])%mod;
            if( hash2 < 0 )
                hash2 += mod;
            if( hash1 == hash2 )
            {
                for( k = i-size2+1, l = 0; k <= i; k++, l++ )
                {
                    if( str[k] != B[l] )
                        break;
                }
                if( l == size2 )
                    return true;                
            }
        }
        return false;
    }
    int repeatedStringMatch(string A, string B) {
        
        int  i, j, size1 = A.size(), size2 = B.size(), hash1 = 0, hash2 = 0;
        int count = 0, mod = 100000;
        string str = "";

        while( str.size() < size2 )
        {
            str += A;
            count++;
        }
        for( i = 0; i < size2; i++ )
        {
            hash1 = (hash1*31 + B[i])%mod;
            hash2 = (hash2*31 + str[i])%mod;
        }
        if( hash1 < 0 )
            hash1 += mod;
        if( hash2 < 0 )
            hash2 += mod;
        if( rabin(str, B, hash1, hash2) )
            return count;
        str += A;
        if( rabin(str, B, hash1, hash2) )
            return count+1;
        return -1;
    }
};
