/*
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.
*/
class Solution {
public:

    struct Node
    {
        int data;
        int rank;
        Node* parent;
    };
    map<int, Node*>mp;
    void makeset( int val )
    {
        Node* node = new Node();
        node->data = val;
        node->rank = 0;
        node->parent = node;
        mp[val] = node;
    }
    void Union( int val1, int val2 )
    {
        Node* node1 = mp[val1];
        Node* node2 = mp[val2];
        Node* parent1 = find(node1);
        Node* parent2 = find(node2);
        if( parent1 == parent2 )
        {
            return;
        }
        if( parent1->rank >= parent2->rank )
        {
            parent1->rank = (parent1->rank == parent2->rank) ? parent1->rank+1 : parent1->rank;
            parent2->parent = parent1;
        }
        else
        {
            parent1->parent = parent2;
        }
    }
    Node* find( Node* node )
    {
        Node* node_parent = node->parent;
        if( node == node_parent )
            return node;
        node->parent = find( node_parent );
        return node->parent;
    }
    int findCircleNum(vector<vector<int>>& M) {
        
        int i, j, row_size = M.size(), col_size = M.size();
        Node* parent;
        map<Node*, int>count;
        for( i = 0; i < M.size(); i++ )
        {
            makeset(i);
        }
        for( i = 0; i < row_size; i++ )
        {
            for( j = i+1; j < col_size; j++ )
            {
                if( M[i][j] == 1 )
                    Union(i, j);
            }
        }
        for( i = 0; i < M.size(); i++ )
        {
            parent = find( mp[i] );
            count[parent] = 1;
        }
        return count.size();
    }
};
