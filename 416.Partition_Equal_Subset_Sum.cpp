/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
 

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
 
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int size = nums.size(), i = 0, j = 0, sum = 0;
        for( i = 0; i < size; i++ )
        {
            sum += nums[i];
        }
        if( (sum&1) == 1 )
            return false;
        sum = sum/2;
        int dp[size][sum+1];
        for( i = 0; i < size; i++ )
        {
            dp[i][0] = 1;
        }
        for( i = 0; i <= sum; i++ )
        {
            dp[0][i] = false;
        }
        if( nums[0] <= sum )
            dp[0][nums[0]] = true; 
        for( i = 1; i < size; i++ )
        {
            for( j = 1; j <= sum; j++ )
            {
                dp[i][j] = dp[i-1][j];
                if (j >= nums[i]) 
                    dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i]]);
            }
        }
        return dp[size-1][sum];
    }
};
