/*
Given an array of integers nums and an integer limit, return the size of the longest continuous subarray such that the absolute difference between any two elements is less than or equal to limit.

In case there is no subarray satisfying the given condition return 0.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= limit <= 10^9


*/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int i, j , size = nums.size(), len = 1, max_len = 1;
        int min = nums[0], max = nums[0];
        for( i = 1 , j = 0; i < size; i++ )
        {
            if( max < nums[i] )
                max = nums[i];
            if( min > nums[i] )
                min = nums[i];
            if( (max-min) > limit )
            {
                j++; 
                min = nums[j];
                max = nums[j];
                for( int k = j + 1; k <= i ; k++ )
                {
                    if( min > nums[k] )
                        min = nums[k];
                    if( max < nums[k] )
                        max = nums[k];
                }
            }
            else
                len++;
            if( max_len < len )
                max_len = len;
        }
        return max_len;
    }
};
