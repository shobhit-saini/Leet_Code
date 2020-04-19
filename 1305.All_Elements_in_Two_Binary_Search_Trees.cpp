/*
Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

 

Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]
Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]
Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]
Example 5:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
 

Constraints:

Each tree has at most 5000 nodes.
Each node's value is between [-10^5, 10^5].
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
    void Inorder( TreeNode* root , vector<int>&v )
    {
        if( root != NULL )
        {
            Inorder( root -> left , v ) ;
            v.push_back( root -> val ) ;
            Inorder( root -> right , v ) ;
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> v1 , v2 , v3 ;
        Inorder( root1 , v1 ) ;
        Inorder( root2 , v2 ) ;
        int size1 = v1.size() , size2 = v2.size() , i = 0 , j = 0 ;
        while( i < size1 && j < size2 )
        {
            if( v1[i] < v2[j] )
            {
                v3.push_back( v1[i] ) ;
                i++ ;
            }
            else
            {
                v3.push_back( v2[j] ) ;
                j++ ;
            }
        }
        while( i < size1 )
        {
            v3.push_back( v1[i] ) ;
            i++ ;
        }
        while( j < size2 )
        {
            v3.push_back( v2[j] ) ;
            j++ ;
        }
        return v3 ;
    }
};
