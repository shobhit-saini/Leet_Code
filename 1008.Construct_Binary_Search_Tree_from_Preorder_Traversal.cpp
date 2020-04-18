/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

 

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Note: 

1 <= preorder.length <= 100
The values of preorder are distinct.
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int size = preorder.size() , i ;
        stack<TreeNode*> s ;
        TreeNode* root = new TreeNode() ;
        root -> val = preorder[0] ;
        TreeNode* root1 = root , *tmp ;
        s.push(root1) ;
        for( i = 1 ; i < size ; i++ )
        {
            TreeNode* root2 = new TreeNode() ; 
            if( s.top() -> val > preorder[i] )
            {
                s.top() -> left = root2 ;
                root2 -> val  = preorder[i] ;
                s.push( root2 ) ;
            }
            else
            {
                while(1)
                {
                    tmp = s.top() ;
                    s.pop() ;
                    if( s.empty() || s.top() -> val > preorder[i] )
                    {
                        tmp -> right = root2 ; 
                        root2  -> val = preorder[i] ;
                        s.push( root2 ) ;
                        break ;
                    }
                }
            }
        }
        return root ;
    }
};
