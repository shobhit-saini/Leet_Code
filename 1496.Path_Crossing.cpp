/*
Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return True if the path crosses itself at any point, that is, if at any time you are on a location you've previously visited. Return False otherwise.

 

Example 1:



Input: path = "NES"
Output: false 
Explanation: Notice that the path doesn't cross any point more than once.
Example 2:



Input: path = "NESWW"
Output: true
Explanation: Notice that the path visits the origin twice.
 

Constraints:

1 <= path.length <= 10^4
path will only consist of characters in {'N', 'S', 'E', 'W}
*/
class Solution {
public:
    bool isPathCrossing(string path) {
        
        int H = 0, V = 0, i, size = path.size();
        set<pair<int, int>>s;
        
        s.insert( {0,0} );
        for( i = 0; i < size; i++ )
        {
            if( path[i] == 'N' )
                V++;
            else if( path[i] == 'S' )
                V--;
            else if( path[i] == 'E' )
                H++;
            else if( path[i] == 'W' )
                H--;
            if(s.find({H,V}) != s.end())
                return true;
            else
                s.insert({H,V});
        }
        return false;
    }
};
