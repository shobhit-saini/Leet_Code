/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/
class Solution {
public:
    int numSquares(int n) {
        
        int i, j;
        vector<int>res(n+1, INT_MAX);
        res[0] = 0;
        vector<int>ps;
        for( i = 1; i*i <= n; i++ )
        {
            ps.push_back(i*i);
        }
        int ps_size = ps.size();
        for( i = 1; i <= n; i++ )
        {
            for( j = 0; j < ps_size; j++ )
            {
                if( ps[j] <= i )
                {
                    if( (res[i-ps[j]] + 1) < res[i] )
                        res[i] = res[i-ps[j]] + 1;
                }
                else
                    break;
            }
        }
        return res[n];
    }
};
