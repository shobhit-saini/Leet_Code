/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
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
