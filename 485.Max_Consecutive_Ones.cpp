/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int size = nums.size() , i , max , len = 0;
        for( i = 0 ; i < size ; i++ )
        {
            if( nums[i] == 0 )
            {
                if( max < len )
                    max = len ;
                len = 0 ;
            }
            else
            {
                len++ ;
            }
        }
        if( max < len )
            return len ;
        return max ;
    }
};
