/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> v(numRows) ;
        int i , j ;
        if( numRows == 0 )
            return v ;
        v[0].push_back(1) ;
        if( numRows == 1 )
            return v ;
        v[1].push_back(1);
        v[1].push_back(1) ;
        if(numRows == 2)
            return v ;
        for( i = 2 ; i < numRows ; i++ )
        {
            v[i].push_back(1) ;
            for( j = 1 ; j < v[i - 1].size() ; j++ )
            {
                v[i].push_back(v[i - 1][j - 1] + v[i - 1][j]) ;
            }
            v[i].push_back(1) ;
        }
        return v ;
    }
};
