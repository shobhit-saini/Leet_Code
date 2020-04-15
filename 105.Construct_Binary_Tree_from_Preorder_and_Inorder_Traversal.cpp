/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
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
    int i = 0 ;
    TreeNode* fun( vector<int>& preorder , vector<int>& inorder , int L , int R )
    {
        if( L > R )
            return NULL ;
        TreeNode* tmp = new TreeNode() ;
        int j ;
        for( j = L ; j <= R ; j++ )
        {
            if( inorder[j] == preorder[i] )
                break ;  
        }
        tmp -> val = preorder[i];
        i++;
        tmp -> left = fun( preorder , inorder , L , j - 1 ) ;
        tmp -> right = fun( preorder , inorder , j + 1 , R ) ;
        return tmp ;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.size() == 0)
            return NULL ;
        return fun( preorder , inorder , 0 , preorder.size() - 1 ) ;
    }
};
