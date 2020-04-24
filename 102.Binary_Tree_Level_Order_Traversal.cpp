/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*>q ;
        vector<int> v1 ;
        vector<vector<int>> v2 ;
        if( root == NULL )
            return v2 ;
        TreeNode* tmp ;
        q.push( root ) ;
        q.push( tmp ) ;
        while( q.front() != tmp )
        {
            v1.clear() ;
            while( q.front() != tmp )
            {
                v1.push_back( q.front() -> val ) ;
                if( q.front() -> left != NULL )
                    q.push( q.front() -> left ) ;
                
                if( q.front() -> right != NULL )
                    q.push( q.front() -> right ) ;
                
                q.pop() ;
            }
            q.pop() ;
            v2.push_back( v1 ) ;
            q.push(tmp) ;
        }
        return v2 ;
    }
};
