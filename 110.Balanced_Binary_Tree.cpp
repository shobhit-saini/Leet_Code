/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
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

    int cal( TreeNode* root )
    {
        if( root == NULL )
            return 0 ;
        int L = cal( root -> left ) ;
        int R = cal( root-> right ) ;
        if( L == -1 || R == -1 || abs(L - R) > 1)
            return -1 ;
        if( L > R )
            return L + 1 ;
        else
            return R + 1 ;
    }
    bool isBalanced(TreeNode* root) {
        
        int res = cal( root ) ;
        if( res == -1 )
            return false ;
        return true ;
    }
};
