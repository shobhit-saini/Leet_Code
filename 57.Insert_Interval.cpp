/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int i, size = intervals.size(), j, start, end, flag = 0;
        vector<int>v;
        vector<vector<int>>result;
        if( size == 0 )
        {
            result.push_back(newInterval);
            return result;
        }
        for( i = 0; i < size; i++ )
        {
            if( intervals[i][1] >= newInterval[0] && flag == 0 )
            {
                if( intervals[i][0] > newInterval[1] )
                {
                    v.push_back(newInterval[0]);
                    v.push_back(newInterval[1]);
                    result.push_back( v );
                    flag = 1;
                }
                else
                {
                    intervals[i][0] = min(intervals[i][0], newInterval[0]);
                    start = intervals[i][0];
                    end = max(intervals[i][1], newInterval[1]);
                    break;
                }
                result.push_back( intervals[i] );
            }
            else
            {
                result.push_back( intervals[i] );
            }
        }
        
        if( i == size && flag == 0 )
        {
            v.push_back(newInterval[0]);
            v.push_back(newInterval[1]);
            result.push_back(v);
            return result;
        }
        if( i == size )
            return result;
        
        for( j = i+1; j < size; j++ )
        {
            if( intervals[j][0] > newInterval[1] )
            {
                break;
            }
        }
        v.push_back(start);
        v.push_back(max(intervals[j-1][1], newInterval[1]));
        result.push_back(v);
        for( int k = j; k < size; k++ )
        {
            result.push_back(intervals[k]);
        }
        return result;
    }
};
