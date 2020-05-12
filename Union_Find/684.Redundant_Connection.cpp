/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

Update (2017-09-26):
We have overhauled the problem description + test cases and specified clearly the graph is an undirected graph. For the directed graph follow up please see Redundant Connection II). We apologize for any inconvenience caused.
*/
class Solution {
public:
    struct Node
    {
        int data;
        int rank;
        Node* parent;
    };
    void makeset( int val, Node* arr[] )
    {
        Node* node = new Node();
        node->data = val;
        node->rank = 0;
        node->parent = node;
        arr[val-1] = node;
    }
    Node* find( Node* node )
    {
        Node* node_parent = node->parent;
        if( node_parent == node )
        {
            return node;
        }
        node->parent = find( node_parent );
        return node->parent;
    }
    bool Union( int val1, int val2, Node* arr[] )
    {
        Node* parent1 = find( arr[val1-1] );
        Node* parent2 = find( arr[val2-1] );
        if( parent1 == parent2 )
            return false;
        if( parent1->rank >= parent2->rank )
        {
            parent1->rank = (parent1->rank == parent2->rank)? parent1->rank+1 : parent1->rank;
            parent2->parent = parent1;
        }
        else
        {
            parent1->parent = parent2;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int i, j, size = edges.size();
        Node* arr[size];
        for( i = 1; i <= size; i++ )
        {
            makeset(i, arr);
        }
        vector<int>v;
        for( i = 0; i < size; i++ )
        {
            if(!Union( edges[i][0], edges[i][1], arr ))
            {
                v.push_back(edges[i][0]);
                v.push_back(edges[i][1]);
                return v;
            }
        }
        return v;
    }
};
