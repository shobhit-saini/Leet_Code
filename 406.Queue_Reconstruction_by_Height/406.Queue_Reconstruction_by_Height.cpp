/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

 
Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/
class Solution {
public:
    static int compare( vector<int>v1, vector<int>v2 )
    {
        return v1[0] > v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        vector<vector<int>>res;
        sort( people.begin(), people.end(), compare );
        for( int i = 0; i < people.size(); i++ )
        {
            res.insert(res.begin()+people[i][1] , people[i]);
        }
        return res;
    }
};
