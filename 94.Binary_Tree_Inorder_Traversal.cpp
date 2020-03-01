/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* pre, *temp = root;
        vector<int> result;
        while(temp != NULL)
        {
            if(temp -> left == NULL)
            {
                //cout << temp->val;
                result.push_back(temp -> val);
                temp = temp->right;
            }
            else
            {
                pre = predecessor(temp);
                if(pre -> right == NULL)
                {
                    pre -> right = temp;
                    temp = temp->left;
                }
                else
                {
                    pre -> right = NULL;
                   // cout << temp->val;
                    result.push_back(temp->val);
                    temp = temp -> right;
                }
            }      
        }
      return result;  
    }
    TreeNode* predecessor(TreeNode* temp)
    {
        TreeNode* c = temp->left;
        while(c->right != temp && c->right != NULL)
        {
            c = c -> right;
        }
        return c;
    }
};
