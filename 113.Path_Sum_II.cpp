/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
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
    void sumpath( TreeNode* root , int sum , vector<vector<int>>&v2 ,vector<int>&v1 )
    {
        if( root != NULL )
        {
            v1.push_back( root -> val ) ;
            if( root -> left == NULL && root -> right == NULL && sum - root -> val == 0 )
                v2.push_back( v1 ) ;
            sumpath( root -> left , sum - root -> val , v2, v1  ) ;
            sumpath( root -> right , sum - root -> val , v2 , v1 ) ;
            v1.pop_back() ;
        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> v2 ;
        vector<int> v1 ;
        sumpath( root , sum , v2 , v1 ) ;
        return v2 ;
    }
};
