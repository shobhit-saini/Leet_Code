/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/
class Solution {
public:
    void com( vector<int>&nums,  vector<int>&res, vector<int>&count, vector<vector<int>>&output, int start, int n, int sum, int k )
    {
        if( sum > n )
            return;
        if( sum == n && res.size() == k )
            output.push_back(res);
        for( int i = start; i < nums.size(); i++ )
        {
            if( count[i] == 0 )
                continue;
            count[i]--;
            res.push_back(nums[i]);
            sum += nums[i];
            com( nums, res, count, output, i+1, n, sum, k );
            sum -= nums[i];
            count[i]++;
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int>nums, res, count;
        vector<vector<int>>output;
        int i;
        for( i = 1; i <= n && i <= 9; i++ )
        {
            nums.push_back(i);
            count.push_back(1);
        }
        com( nums, res, count, output, 0, n, 0, k );
        return output;
    }
};
