/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    int var = 0 , flag = 0 ;
    void fun ( TreeNode* root , int sum )
    {
        var += root -> val ; 
        if( root -> left == NULL && root -> right == NULL )
        {
            if( var == sum )
            {
                flag = 1;
            }
            var -= root -> val ;
            return ;
        }
        if( root -> left != NULL )
        {
            fun( root -> left , sum ) ;
        }
        if( root -> right != NULL )
        {
            fun( root -> right , sum ) ; 
        }
        var -= root -> val ;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        
        if( root == NULL )
            return 0 ;
        fun ( root , sum ) ;
        if( flag == 1 )
            return true ;
        return false ;
    }
};
