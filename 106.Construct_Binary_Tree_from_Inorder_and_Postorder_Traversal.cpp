/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
    int i ;
    TreeNode* fun( vector<int>& inorder ,vector<int>& postorder , int L , int R )
    {
        if( L > R )
            return NULL ;
        TreeNode* tmp = new TreeNode() ;
        int j ;
        for( j = 0 ; j < inorder.size() ; j++ )
        {
            if( postorder[i] == inorder[j] )
                break ;
        }
        tmp -> val = inorder[j];
        i-- ;
        tmp -> right = fun( inorder , postorder , j + 1 , R );
        tmp -> left = fun( inorder , postorder , L , j - 1 );
        return tmp ;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if( inorder.size() == 0 && postorder.size() == 0 )
            return NULL ;
        i = inorder.size() - 1 ;
        return fun( inorder , postorder , 0 , inorder.size() - 1 );
    }
};
