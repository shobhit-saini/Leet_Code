/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
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
    TreeNode* root1 ;
    int max = 0 ;
    int bt( TreeNode*root )
    {
        if( root == NULL )
            return 0;
        int L = bt( root -> left ) ;
        int R = bt( root -> right ) ;
        int val = (L + R) ;
        if( max < val )
            max = val ;
        if( root == root1 )
            return max ;
        if( L > R )
            return L + 1 ;
        else
            return R + 1 ;
    
    }
    int diameterOfBinaryTree(TreeNode* root) {
        root1 = root ;
        return bt(root) ;
    }
};
