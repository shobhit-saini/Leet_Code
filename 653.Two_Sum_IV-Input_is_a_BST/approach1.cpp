/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
 

Example 2:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
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
    void Inorder(TreeNode* root, vector<int>&v)
    {
        if(root == NULL)
            return;
            Inorder(root->left, v);
            v.push_back(root->val);
            Inorder(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        Inorder(root, v);
        int i = 0, j = v.size()-1, sum;
        while(i != j)
        {
            sum = v[i] + v[j];
            if(sum == k)
                return true;
            else if(sum < k)
                i++;
            else
                j--;
        }
        return false;
    }
};
