/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        
        unsigned long long i = 1, mid, low, high;
        while( 1 )
        {
            if( i*i == num )
                return true;
            if( i*i > num )
            {
                high = i;
                low = i/2;
                break;
            }
            i = i*2;
        }
        while( low <= high )
        {
            mid = (low+high)/2;
            if( mid*mid == num )
                return true;
            else if( mid*mid > num )
                high = mid-1;
            else
                low = mid+1;
        }
        return false;
    }
};
