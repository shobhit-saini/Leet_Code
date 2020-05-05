/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/
class Solution {
public:
    void com( vector<int>A, vector<int>&count, vector<int>&res, vector<vector<int>>&output, int target, int sum, int size, int start )
    {
        if( sum == target )
            output.push_back(res);
        if( sum > target )
            return;
        for( int i = start; i < A.size(); i++ )
        {
            if( count[i] == 0 )
                continue;
            count[i]--;
            sum += A[i];
            res.push_back(A[i]);
            com( A, count, res, output, target, sum, size, i );
            res.pop_back();
            sum -= A[i];
            count[i]++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        map<int, int>mp;
        int i, size = candidates.size();
        vector<int>res, count, A;
        vector<vector<int>>output;
        for( i = 0; i < size; i++ )
        {
            mp[candidates[i]] += 1;
        }
        map<int, int>:: iterator itr;
        for( itr = mp.begin(); itr != mp.end(); itr++ )
        {
            A.push_back(itr->first);
            count.push_back(itr->second);
        }
        com( A, count, res, output, target, 0, size, 0 );
        return output;
    }
};
