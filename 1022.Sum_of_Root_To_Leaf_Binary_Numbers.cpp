/*
Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.

 

Example 1:



Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 

Note:

The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.

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
    int binarytointeger( vector<int>& v )
    {
        int res = 0 , i = 0 ;
        while( i < v.size() )
        {
            res = (res << 1) | v[i] ;
            i++ ;
        }
        return res ;
    }
    int sum_fun( TreeNode* root, vector<int>& v, int& sum )
    {
       if( root != NULL )
       {
            v.push_back(root -> val);
            if( root -> left == NULL && root -> right == NULL )
                sum += binarytointeger( v );     
            sum_fun( root -> left , v , sum ) ;
            sum_fun( root -> right , v , sum ) ;
            v.pop_back() ;
        }
        return sum ;
        
        
    }
    int sumRootToLeaf(TreeNode* root) {
        
        vector<int> v ;
        int sum = 0 ;
        return sum_fun( root , v , sum );
    }
};
