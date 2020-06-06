/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/
class Solution {
public:
    bool static comp( vector<int>v1, vector<int>v2 )
    {
        return v1[0] < v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> res ;
        if( intervals.size() == 0 )
            return res;
        sort( intervals.begin() , intervals.end(), comp ) ;
        res.push_back(intervals[0]);
        int size = intervals.size() , i , j ;
        for( i = 1; i < size; i++ )
        {
            if( res.back()[1] < intervals[i][0]  )
                res.push_back(intervals[i]);
            else
                res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        
        return res;
    }
};
