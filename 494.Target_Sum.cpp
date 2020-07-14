/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
 

Constraints:

The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        
        int nums_size = nums.size(), i, sum = 0, j;
        for( i = 0; i < nums_size; i++ )
        {
            sum += nums[i]; 
        }
        
        //equation1: (sum+ve) - (sum-ve) = target
        //equation2: (sum+ve) + (sum-ve)= total_sum
        // (sum+ve) = (target + total_sum)/2
        //Find out the number of subsets whose sum is equals to sum+ve;
        
        int sum_p = 0, count = 0;
        if( sum < S || (S + sum) % 2 != 0 )
            return 0;
        
        sum_p = (S + sum)/2;
        sort(nums.begin(), nums.end());
        for( i = 0; i < nums_size; i++ )
        {
            if( nums[i] == 0 )
                count++;
        }
        int dp[nums_size][sum_p + 1];
        
        for( i = 0; i < nums_size; i++ )
        {
            for( j = 0; j <= sum_p; j++ )
            {
                if( j == 0 )
                    dp[i][j] = 1;
                else if( i == 0 )
                {
                    if( nums[i] == j )
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                else
                {
               
                    if( nums[i] <= j )
                        dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]];
                    else
                        dp[i][j] = dp[i-1][j];
                }
                    
            }
        }
        return dp[nums_size-1][sum_p] * pow(2,count);
    }
};
