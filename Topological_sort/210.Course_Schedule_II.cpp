/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses, 0);
        vector<int>output, output1;
        queue<int>q;
        int i, count = 0, u, j;
        for( i = 0; i < prerequisites.size(); i++ )
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for( i = 0; i < numCourses; i++ )
        {
            for( j = 0; j < adj[i].size(); j++ )
                indegree[adj[i][j]]++;
        }
        for( i = 0; i < numCourses; i++ )
        {
            if( indegree[i] == 0 )
                q.push(i);
        }
        while( !q.empty() )
        {
            u = q.front();
            q.pop();
            for( i = 0; i < adj[u].size(); i++ )
            {
                if( --indegree[adj[u][i]] == 0 )
                    q.push(adj[u][i]);
            }
            output.push_back(u);
            count++;
        }
        if( count != numCourses )
            return output1;
        reverse(output.begin(), output.end());
        return output;
    }
};
