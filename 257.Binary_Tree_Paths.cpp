/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    void path( TreeNode* root, vector<string>&v, string str )
    {
        if( root == NULL )
            return ;
        str += to_string(root->val);
        str += "->";
        if( root -> left == NULL && root -> right == NULL )
        {
            str.pop_back();
            str.pop_back();
            v.push_back(str);
            return;
        }
        if( root->left != NULL )
        {
            path(root->left, v, str);
            
        }
        if( root->right != NULL )
        {    
            path(root->right, v,str);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string>v;
        string str = "";
        int i, j;
        path(root, v, str);
        return v;
    }
};
