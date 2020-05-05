/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
class Solution {
public:
    void sub( vector<int>A, vector<int>count, vector<int>res, vector<vector<int>>&output, int start )
    {
        output.push_back(res);
        for( int i = start; i < A.size(); i++ )
        {
            if( count[i] == 0 )
                continue;
            res.push_back(A[i]);
            count[i]--;
            sub( A, count, res, output, i );
            count[i]++;
            res.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>>output;
        vector<int>res, count, A;
        map<int, int>mp;
        int i, size = nums.size();
        for( i = 0; i < size; i++ )
        {
            mp[nums[i]] += 1;
        }
        map<int, int>:: iterator itr;
        for( itr = mp.begin(); itr != mp.end(); itr++ )
        {
            A.push_back(itr -> first);
            count.push_back(itr -> second);
        }
        sub( A, count, res, output, 0 );
        return output;
    }
};
