/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
class Solution {
public:
    void permute( vector<int>nums, vector<int>count, vector<int>&res, vector<vector<int>>&output, int level )
    {
        if( level == nums.size() )
        {
            output.push_back(res);
            return;
        }
        for( int i = 0; i < nums.size(); i++ )
        {
            if( count[i] == 0 )
                continue;
            res[level] = nums[i];
            count[i]--;
            permute( nums, count, res, output, level+1 );
            count[i]++;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        int i, size = nums.size();
        vector<int>count(size);
        vector<int>res(size);
        vector<vector<int>>output;
        for( i = 0; i < size; i++ )
        {
            count[i] = 1;
        }
        permute( nums, count, res, output, 0 );
        return output;
    }
};
