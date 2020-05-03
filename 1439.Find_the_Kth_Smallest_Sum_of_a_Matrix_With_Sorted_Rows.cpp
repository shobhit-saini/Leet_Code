/*
You are given an m * n matrix, mat, and an integer k, which has its rows sorted in non-decreasing order.

You are allowed to choose exactly 1 element from each row to form an array. Return the Kth smallest array sum among all possible arrays.

 

Example 1:

Input: mat = [[1,3,11],[2,4,6]], k = 5
Output: 7
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.  
Example 2:

Input: mat = [[1,3,11],[2,4,6]], k = 9
Output: 17
Example 3:

Input: mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
Output: 9
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]. Where the 7th sum is 9.  
Example 4:

Input: mat = [[1,1,10],[2,2,9]], k = 7
Output: 12
 

Constraints:

m == mat.length
n == mat.length[i]
1 <= m, n <= 40
1 <= k <= min(200, n ^ m)
1 <= mat[i][j] <= 5000
mat[i] is a non decreasing array.
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        
        set<vector<int>>s;
        priority_queue <pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>> > pq;
        vector<int>v, v1, v2;
        int i, size = mat.size(), sum = 0, var = 0, sum1;
        for( i = 0; i < size; i++ )
        {
            v.push_back(0);
            sum += mat[i][0];
        }
        pair<int, vector<int>>tmp = { sum, v };
        pq.push( tmp );
        while( var < k )
        {
            tmp = pq.top();
            pq.pop();
            sum = tmp.first;
            v1.push_back(tmp.first);
            v = tmp.second;
            for( i = 0; i < size; i++ )
            {
                sum1 = sum;
                v2 = v;
                if( v2[i] < mat[i].size() - 1 )
                {
                   
                    sum1 -= mat[i][v2[i]];
                    v2[i]++;
                    sum1 += mat[i][v2[i]];
                    if( s.find(v2) == s.end() )
                    {
                        tmp = { sum1, v2 }; 
                        pq.push(tmp);
                        s.insert(v2);
                    }
                }
            }
            var++;
        }
        return v1[k - 1];
    }
};
