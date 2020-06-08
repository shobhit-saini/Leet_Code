/*
Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        int i, flag = 0;
        if( n <= 0 )
            return false;
        for( i = 0; i < 32; i++ )
        {
            if( (1 & n >> i) && flag == 0 )
            {
                flag = 1;
            }
            else if( (1 & n >> i) && flag == 1 )
            {
                break;
            }
        }
        if( i < 32 )
        {
            return false;
        }
        
        return true;
    }
};
