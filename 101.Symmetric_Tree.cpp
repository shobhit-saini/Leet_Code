/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Follow up: Solve it both recursively and iteratively.
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
    int flag = 0 ;
    void MI( TreeNode* root , TreeNode* root1 )
    {
    if( root == NULL || root1 == NULL )
        return ;
  
    if((root -> left == NULL && root1 -> right != NULL) || (root -> right == NULL && root1 -> left != NULL))
        flag = 1 ;
    else if( root -> val != root1 -> val )
        flag = 1 ;
        MI( root -> left , root1 -> right ) ;
        MI( root -> right , root1 -> left ) ;     
    }
    bool isSymmetric(TreeNode* root) {
        
        TreeNode* root1 = root ;
        MI( root , root1 );
        if( flag == 1 )
            return false ;
        return true ;
    }
};
