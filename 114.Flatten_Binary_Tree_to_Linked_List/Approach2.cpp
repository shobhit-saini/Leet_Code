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

    void flatten(TreeNode* root) {
        

        if( root == NULL )
            return ;
        if( root -> right == NULL && root -> left == NULL )
            return ;
        TreeNode* tmp1 , *tmp2 ;
        tmp1 = root -> right ;
        root -> right = root -> left ;
        root -> left = NULL ;
        tmp2 = root ;
        while( tmp2 -> right != NULL )
        {
            tmp2 = tmp2 -> right ;
        }
        tmp2 -> right = tmp1 ;
        flatten( root -> right );        
    }
};
