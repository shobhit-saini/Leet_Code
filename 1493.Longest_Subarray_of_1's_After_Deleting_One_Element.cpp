/*
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array.

Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
Example 4:

Input: nums = [1,1,0,0,1,1,1,0,1]
Output: 4
Example 5:

Input: nums = [0,0,0]
Output: 0
 

Constraints:

1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int size = nums.size(), pre[size], suff[size], max = INT_MIN, i, count = 0;
        if( size == 1 )
            return 0;
        for( i = 0; i < size; i++ )
        {
            if( nums[i] == 1 )
                count++;
            else
                count = 0;
            pre[i] = count;
        }

        count = 0;
        for( i = size-1; i >= 0; i-- )
        {
            if( nums[i] == 1 )
                count++;
            else
                count = 0;
            suff[i] = count;
        }
        
        if( suff[0] == size )
            return size-1;
        for( i = 0; i < size; i++ )
        {
            if( i == 0 )
            {
                if( pre[i] == 0 )
                {
                    if( max < suff[i+1] )
                        max = suff[i+1];
                }
            }
            else if( i == size-1 )
            {
                if( pre[i] == 0 )
                {
                    if( max < pre[i-1] )
                        max = pre[i-1];
                }
            }
            else if( pre[i] == 0 )
            {
                if( max < (pre[i-1] + suff[i+1]))
                {
                    max = pre[i-1] + suff[i+1];
                }
            }
        }
        return max;
    }
};
