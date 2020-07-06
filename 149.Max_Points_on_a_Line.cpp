/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
Example 2:

Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        if( points.size() < 2 )
            return points.size();
        map<pair<long double, long double>, int>mp;
        int i, j, size = points.size(), maxi = INT_MIN, flag = 0;
        long double m, c;
        pair<long double, long double>temp;
        map<pair<long double, long double>, int>::iterator itr;
        for( i = 0; i < size; i++ )
        {
            for( j = 0; j < size; j++ )
            {
                if( i == j )
                    continue;
                if( points[i][0] == points[j][0] && points[i][1] == points[j][1] )
                    flag++;
                else if( (points[j][0]-points[i][0]) == 0 )
                {
                    m = INT_MAX;
                    c = 0;
                    temp = {m, c};
                    mp[temp]++;
                }
                else
                {
                    m = (long double)(points[j][1]-points[i][1])/(points[j][0]-points[i][0]);
                    c = ((long double)points[i][1] - m*(long double)points[i][0]);
                    temp = {m, c};
                    mp[temp]++;
                }
            }
            if( maxi < flag )
                maxi = flag;
            for( itr = mp.begin(); itr != mp.end(); itr++ )
            {
                if( maxi < itr->second+flag )
                    maxi = itr->second+flag;
            }
            mp.clear();
            flag = 0;
        }
        return maxi+1;
    }
};
