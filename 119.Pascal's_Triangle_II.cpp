/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<vector<int>>v(rowIndex+1);
        int i = 0, j, temp;
        v[0].push_back(1);
        i++;
        while( i <= rowIndex )
        {
            v[i].push_back(1);
            for( j = 1; j < v[i-1].size(); j++ )
            {
                temp = v[i-1][j]+v[i-1][j-1];
                v[i].push_back(temp);
            }
            v[i].push_back(1);
            i++;
        }
        return v[rowIndex];
    }
};
