/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
 

Note:

There are at least two nodes in this BST.
This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
    int getMinimumDifference(TreeNode* root) {
        
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
