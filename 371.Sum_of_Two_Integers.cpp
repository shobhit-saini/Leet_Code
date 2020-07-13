/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1
*/
class Solution {
public:
    int getSum(int a, int b) {
        
        int sum = 0, cin = 0, power = 0;
        for( int i = 0; i < 32; i++ )
        {
            sum += ((a & 1)^(b & 1)^(cin)) << i;
            cin = (a&1)*(b&1) | (cin)*(a&1 ^ b&1);
            a = a >> 1;
            b = b >> 1;
        
        }
        return sum;
    }
};
