/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

 

 

Example 1:



Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:



Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
 
*/
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
     
        int i, size = coordinates.size();
        if( size == 1 )
            return true;
        float m, c;
        pair<float, float>pr;
        map<pair<float, float>, int>mp;
        for( i = 0; i < size-1; i++ )
        {
            if( coordinates[i+1][0] - coordinates[i][0] == 0 )
            {
                m = INT_MAX;
                c = 0;
            }
            else
            {
                m = (coordinates[i+1][1] - coordinates[i][1])/(coordinates[i+1][0] - coordinates[i][0]);
                c = coordinates[i][1] - m*coordinates[i][0];
            }
            pr = { m, c };
            mp[pr] = 1;
        }
        if( mp.size() == 1 )
            return true;
        return false;
    }
};
