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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> v2 ;
        vector<int>v1(2) ;
        sort( intervals.begin() , intervals.end() ) ;
        int size = intervals.size() , i , j , max ;
        for( i = 0 ; i < size ;  )
        {
            v1[0] = intervals[i][0] ;
            max = intervals[i][1] ;
            j = i + 1 ;
            if( j == size )
            {
                v1[1] = intervals[i][1] ;
                
            }
            else
            {
                while( 1 )
                {
                    if( j == size )
                    {
                        v1[1] = max ;
                        break ;
                    }
                    else
                    {
                        if( max < intervals[j][0] )
                        {
                            v1[1] = max ; 
                            break ;
                        }
                        else 
                        {
                            max = max > intervals[j][1] ? max : intervals[j][1] ;
                        }
                    }
                    j++ ;
                }
            }
             v2.push_back(v1) ;
            i = j ;
        }
        return v2 ;
    }
};
