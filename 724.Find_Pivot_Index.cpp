/*
Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of all the numbers to the left of the index is equal to the sum of all the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

 

Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.
Example 2:

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
 

Constraints:

The length of nums will be in the range [0, 10000].
Each element nums[i] will be an integer in the range [-1000, 1000].
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        if( nums.size() == 0 )
            return -1;
        if( nums.size() == 1 )
            return 0;
        int i, size = nums.size(), pre[size], suff[size];
        pre[0] = nums[0];
        for( i = 1; i < size; i++ )
        {
            pre[i] = pre[i-1] + nums[i];
        }
        suff[size-1] = nums[size-1];
        for( i = size-2; i >= 0; i-- )
        {
            suff[i] = nums[i] + suff[i+1];
        }

        if( suff[1] == 0 )
            return 0;
        for( i = 1; i < size-1; i++ )
        {
            if( pre[i-1] == suff[i+1] )
                return i;
        }

        if( pre[size-2] == 0 )
            return size-1;
        return -1;
    }
};
