/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
class Solution {
public:
    void permute( vector<int>input, vector<int>res, vector<int>count, vector<vector<int>>&output, int level, int size )
    {
        if( level == size )
        {
            output.push_back(res);
            return;
        }
        for( int i = 0; i < input.size(); i++ )
        {
            if( count[i] == 0 )
                continue;
            res[level] = input[i];
            count[i]--;
            permute( input, res, count, output, level+1, size );
            count[i]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        int i, size = nums.size();
        map<int, int>mp;
        for( i = 0; i < size; i++ )
        {
            mp[nums[i]] += 1;
        }
        vector<int>input, res(size), count;
        vector<vector<int>>output;
        map<int, int>:: iterator itr;
        for( itr = mp.begin(); itr != mp.end(); itr++ )
        {
            input.push_back(itr -> first);
            count.push_back(itr -> second);
        }
        permute( input, res, count, output, 0, size );
        return output;
    }
};
