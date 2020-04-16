/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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
    void preorder( TreeNode* root , vector<TreeNode*>&v )
    {
        if( root != NULL )
        {
            v.push_back(root) ;
            preorder(root -> left , v) ;
            preorder(root -> right , v) ;
        }
    }
    void flatten(TreeNode* root) {
        
        vector<TreeNode*> v ;
        int i ;
        preorder( root , v ) ;
        for( i = 1 ; i < v.size() ; i++ )
        {
            root -> right = v[i] ;
            root -> left = NULL ;
            root = root -> right ;
        }
        /*if( root == NULL )
            return ;
        if( root -> right == NULL && root -> left == NULL )
            return ;
        TreeNode* tmp ;
        tmp = root -> right ;
        root -> right = root -> left ;
        root -> left = NULL ;
        flatten( root -> right );        
        root -> right -> right  = tmp ;*/
    }
};
