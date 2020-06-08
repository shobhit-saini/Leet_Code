/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort( nums.begin(), nums.end() );
        int i, size = nums.size(), j, k;
        vector<vector<int>>temp(size);
        for( i = 0; i < size; i++ )
        {
            temp[i].push_back(nums[i]);
        }
        for( i = 1; i < size; i++ )
        {
            for( j = 0; j < i; j++ )
            {
                if( nums[i]%nums[j] == 0 )
                {
                    if( temp[i].size() < temp[j].size()+1 )
                    {
                        temp[i].clear();
                        temp[i].push_back(nums[i]);
                        for( k = 0; k < temp[j].size(); k++ )
                        {
                            temp[i].push_back(temp[j][k]);
                        }
                    }
                }
            }
        }
        
        int index = -1;
        vector<int>res;
        for( i = 0; i < size; i++ )
        {
            if( res.size() < temp[i].size() )
            {
                res = temp[i];
            }
        }
        return res;
    }
};
