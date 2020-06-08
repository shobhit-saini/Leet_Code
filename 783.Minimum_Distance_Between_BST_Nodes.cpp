/*
Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
        /   \
      2      6
     / \    
    1   3  

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
Note:

The size of the BST will be between 2 and 100.
The BST is always valid, each node's value is an integer, and each node's value is different.
This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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
    void inorder( TreeNode* root, vector<int>&v1 )
    {
        if( root != NULL )
        {
            inorder( root-> left, v1);
            v1.push_back(root->val);
            inorder( root-> right, v1 );
        }
    }
    int minDiffInBST(TreeNode* root) {
        
        vector<int>v1;
        inorder( root, v1 );
        int size = v1.size(), i, diff, max_diff = INT_MAX;
        for( i = 0; i < size-1; i++ )
        {
            diff = v1[i+1] - v1[i];
            if( max_diff > diff  )
                max_diff = diff;
        }
        return max_diff;
    }
};
