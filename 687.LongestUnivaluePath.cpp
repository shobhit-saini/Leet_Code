/*
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

The length of path between two nodes is represented by the number of edges between them.

 

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2

 

Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2

 

Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int path( TreeNode* root, int pre, int& len )
    {
        if( root == NULL )
            return 0;
        int left = path(root->left, root->val, len);
        int right = path(root->right, root->val, len);
        len = max( len, left+right );
        if( pre == root->val )
            return max(left, right) + 1;
        return 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        
        int max_val = 0, pre = INT_MIN;
        if( root == NULL )
            return 0;
        path( root, root->val, max_val );
        return max_val;
    }
};
