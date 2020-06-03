/*
There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

 

Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
 

Note:

1 <= costs.length <= 100
It is guaranteed that costs.length is even.
1 <= costs[i][0], costs[i][1] <= 1000
*/
class Solution {
public:
    bool static comparator(vector<int>&v1, vector<int>&v2)
    {
        return abs(v1[0] - v1[1]) > abs(v2[0] - v2[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int i, size = costs.size(), A = 0, B = 0, sum = 0, half = size/2;
        sort(costs.begin(), costs.end(), comparator);
        for( i = 0; i < size; i++ )
        {
            if( A < half && B < half )
            {
                if( costs[i][0] < costs[i][1] )
                {
                    sum += costs[i][0];
                    A++;
                }
                else
                {
                    sum += costs[i][1];
                    B++;
                }
            }
            else if( A < half )
            {
                sum += costs[i][0];
                A++;
            }
            else
            {
                sum += costs[i][1];
                B++;
            }
        }
        return sum;
    }
};
