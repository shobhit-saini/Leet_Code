/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        
        if( nums.size() == 0 )
            return 0;
        int size = nums.size() , i , j , dp[size] , maxi ;
        if( size == 1 )
            return nums[0];
        if( size == 2 )
            return max( nums[0] , nums[1] );
        dp[0] = nums[0]; dp[1] = nums[1] ;
        for( i = 2 ; i < size ; i++ )
        {
            maxi = INT_MIN ;
            for( j = 0 ; j < i - 1 ; j++ )
            {
                if( maxi < dp[j] )
                    maxi = dp[j] ;
            }
            dp[i] = maxi + nums[i];
        }
        maxi = 0;
        for( i = 0 ; i < size ; i++ )
        {
            if( maxi < dp[i] )
                maxi = dp[i];
        }
        return maxi ;
    }
};
