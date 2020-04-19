/*
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Constraints:

Both of the given trees will have between 1 and 200 nodes.
Both of the given trees will have values between 0 and 200
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
    void seq_fun( TreeNode* root , vector<int>&v )
    {
        if( root == NULL )
            return ;
        if( root -> left == NULL && root -> right == NULL )
            v.push_back(root -> val) ;
        seq_fun( root -> left , v ) ;
        seq_fun( root -> right , v ) ;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> v1 , v2 ;
        seq_fun( root1 , v1 ) ;
        seq_fun( root2 , v2 ) ;
        if( v1 == v2 )
            return true ;
        return false ;
    }
};
