/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>indegree(numCourses, 0);
        int i, j, u, count = 0;
        queue<int>q;
        vector<vector<int>>adj(numCourses);
        for( i = 0; i < prerequisites.size(); i++ )
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for( i = 0; i < numCourses; i++ )
        {
            for( j = 0; j < adj[i].size(); j++ )
            {
                indegree[adj[i][j]]++;
            }
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
            count++;
        }
        if( count != numCourses )
            return false;
        return true;
    }
};
