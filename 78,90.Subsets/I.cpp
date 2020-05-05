/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class Solution {
public:
    void sub( vector<int>nums, vector<int>res, vector<int>count, vector<vector<int>>&output, int start )
    {
        output.push_back( res );
        for( int i = start; i < nums.size(); i++ )
        {
            if( count[i] == 0 )
                continue;
            res.push_back( nums[i] );
            count[i]--;
            sub( nums, res, count, output, i );
            count[i]++;
            res.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>output;
        vector<int>res, count;
        int i, size = nums.size();
        for( i = 0; i < size; i++ )
        {
            count.push_back( 1 );
        }
        sub( nums, res, count, output, 0 );
        return output;
    }
};
