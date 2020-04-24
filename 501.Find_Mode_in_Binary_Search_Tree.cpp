/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

For example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2
 

return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
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
    void inorder( TreeNode* root , map<int , int>&mp )
    {
        if( root != NULL )
        {
            inorder( root -> left , mp ) ;
            mp[root -> val] += 1 ;
            inorder( root -> right , mp ) ;
        }
    }
    vector<int> findMode(TreeNode* root) {
        
        int max = -1 ;
        vector<int> v ;
        map<int , int> mp ;
        inorder( root , mp ) ;
        map<int , int>:: iterator itr ;
        for( itr = mp.begin() ; itr != mp.end() ; itr++ )
        {
            if( max < itr -> second )
                max = itr -> second ;
        }
        
        for( itr = mp.begin() ; itr != mp.end() ; itr++ )
        {
            if( itr -> second == max )
                v.push_back(itr -> first) ;
        }
        return v ;
    }
};
