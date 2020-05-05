/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/
class Solution {
public:
    void sub( vector<int>&nums, vector<int>&res, vector<int>&count, vector<vector<int>>&output, int start, int sum, int target )
    {
        if( sum > target )
            return;
        if( sum == target )
            output.push_back( res );

        for( int i = start; i < nums.size(); i++ )
        {
            res.push_back( nums[i] );
            sum += nums[i];
            sub( nums, res, count, output, i, sum, target );
            sum -= nums[i];
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>output, output1;
        vector<int>res, count;
        int i, size = candidates.size(), j, sum;
        for( i = 0; i < size; i++ )
        {
            count.push_back( 1 );
        }
        sub( candidates, res, count, output, 0, 0, target);
        return output;
    }
};
