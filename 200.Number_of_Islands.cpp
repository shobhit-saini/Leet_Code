/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
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
        arr[val] = node;
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
        Node* parent1 = find( arr[val1] );
        Node* parent2 = find( arr[val2] );
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
    int numIslands(vector<vector<char>>& grid) {
        
        if( grid.size() == 0 )
            return 0;
        int i, j, row_size = grid.size(), col_size = grid[0].size();
        Node* arr[row_size*col_size];
        map<Node*, int>count;
        for( i = 0; i < row_size; i++ )
        {
            for( j = 0; j < col_size; j++ )
            {
                makeset((i*col_size + j), arr);
            }
        }
        for( i = 0; i < row_size; i++ )
        {
            for( j = 0; j < col_size; j++ )
            {
                
                if(grid[i][j] == '1')
                {
                    if(i - 1 >= 0 && grid[i - 1][j] == '1')
                        Union(i * col_size + j, (i - 1) * col_size + j, arr);
                    if(j - 1 >= 0 && grid[i][j - 1] == '1')
                        Union(i * col_size + j, i * col_size + j - 1, arr);
                }
            }
        }
            for( i = 0; i < row_size; i++ )
            {
                for( j = 0; j < col_size; j++ )
                {
                    if( grid[i][j] == '1' )
                        count[find( arr[i*col_size+j] )] = 1;
                }
            }
        
        return count.size();
    }
};
