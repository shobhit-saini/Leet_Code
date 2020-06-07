/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
    void sum_L(TreeNode* root, int flag, int& sum)
    {
        if( root == NULL )
            return;
        if( root->left == NULL && root->right == NULL && flag == 0 )
        {
            sum += root->val;
        }
        if( root->left != NULL )
            sum_L(root->left, 0, sum);
        if( root->right != NULL )
            sum_L(root->right, 1, sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        
        int sum = 0, flag = -1;
        sum_L(root, flag, sum);
        return sum;
    }
};
