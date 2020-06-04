/*
In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to closest person.

Example 1:

Input: [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
Note:

1 <= seats.length <= 20000
seats contains only 0s or 1s, at least one 0, and at least one 1.
*/
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int flag = 0, i = 0, size = seats.size(), max_so_far = INT_MIN, count = 0, j;
        while( seats[i] != 1 )
        {
            count++;
            i++;
        }
        max_so_far = count;
        for( j = i; j < size; j++ )
        {
            if( seats[j] == 1 && flag == 0)
            {
                flag = 1;
                count = 0;
            }
            else if(seats[j] == 1 && flag == 1)
            {

                if(  max_so_far < (count = (count%2 == 0 ? (count/2):((count/2)+1))) )
                {
                    max_so_far = count;
                }
                count = 0;
            }
            else
            {
                count++;
            }
        }
        if( seats[size-1] == 0 )
        {
            if( max_so_far < count )
            {
                max_so_far = count;
            }
        }
        return max_so_far;
    }
};
