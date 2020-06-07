/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>res;
        if( root == NULL )
            return res;
        queue<TreeNode*>q;
        TreeNode* dummy = new TreeNode();
        TreeNode* a;
        q.push(root);
        q.push(dummy);
        while( q.size() > 1 )
        {
            a = q.front();
            q.pop();
            if( a == dummy )
            {
                q.push(dummy);
                continue;
            }

            if( dummy == q.front() )
            {
                res.push_back(a->val);
            }
            if( a->left != NULL )
                q.push(a->left);
            if( a->right != NULL )
                q.push(a->right);
        }
        return res;
    }
};
