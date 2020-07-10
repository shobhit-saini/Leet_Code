/*
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/

class Solution {
public:
    int countPrimes(int n) {
        
        if( n <= 2 )
            return 0;
        int i, count = 0, j;
        vector<int>v(n, 0);
        for( i = 2; i < n; i++ )
        {
            if( v[i] )
                continue;
            count++;
            for( j = 2; j*i < n; j++ )
            {
                v[i*j] = 1;
            }
        }
        return count;
    }
};
