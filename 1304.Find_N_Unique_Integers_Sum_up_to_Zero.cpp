/*
Given an integer n, return any array containing n unique integers such that they add up to 0.

 

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]
 

Constraints:

1 <= n <= 1000

*/
class Solution {
public:
    vector<int> sumZero(int n) {
        int temp = n % 2, i, t1;
        vector<int>v;
        if(temp == 0)
        {
            t1 = n/2;
            for(i = t1; i > 0; i--)
            {
                v.push_back(-i);
            } 
            for(i = 1; i <= t1; i++)
            {
                v.push_back(i);
            }
        }
        if(temp == 1)
        {
            t1 = (n-1)/2;
            for(i = t1; i > 0; i--)
            {
                v.push_back(-i);
            }
            v.push_back(0);
            for(i = 1; i <= t1; i++)
            {
                v.push_back(i);
            }
        }
        return v;
    }
};
