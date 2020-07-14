/*
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
 

Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.
*/
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int i, j, sum = 0, nums_size = nums.size();
        for( i = 0; i < nums_size; i++ )
        {
            sum += nums[i];
        }
        
        if( sum % k != 0 )
            return false;
        
        vector<int>visited(nums_size, 0);
        sum = sum/k;
        return possible( nums, k, sum, visited, 0, 0 );
    }
    
    bool possible( vector<int>& nums, int k, int target_sum, vector<int>& visited, int curr_sum, int next_index )
    {
        if( k == 0 )
        {
            return true;
        }
        
        if( curr_sum == target_sum )
        {
            if( possible(nums, k-1, target_sum, visited, 0, 0) )
                return true;
        }
        else
        {
            for( int i = next_index; i < nums.size(); i++ )
            {
                if( !visited[i] && curr_sum + nums[i] <= target_sum )
                {
                    visited[i] = 1;
                    if( possible(nums, k, target_sum, visited, curr_sum + nums[i], i+1) )
                        return true;
                    visited[i] = 0;
                }
            }
        }
        return false;
    }
};
