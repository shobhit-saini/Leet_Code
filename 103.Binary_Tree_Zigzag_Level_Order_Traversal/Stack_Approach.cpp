/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
      
        stack<TreeNode*> s1 , s2 ;
        int i = 0 ;
        vector<int> v1 ;
        TreeNode* tmp ;
        vector<vector<int>> v2 ;
          if( root == NULL )
            return v2;
        s1.push(root) ;
        while( !s1.empty() )
        {
            v1.clear() ;
            while( !s1.empty() )
            {
                tmp = s1.top() ;
                s2.push(tmp) ;
                if( i % 2 != 0  )
                    v1.push_back(tmp -> val) ;
                else
                    v1.insert(v1.begin() , tmp -> val) ;
                s1.pop() ;
            }
            v2.push_back(v1) ;
            while( !s2.empty() )
            {
                tmp = s2.top() ;
                if( tmp -> left != NULL )
                    s1.push(tmp -> left) ;
                if( tmp -> right != NULL )
                    s1.push(tmp -> right) ;
                s2.pop() ;
            }
            i++ ;
        }
        return v2 ;
    }
};
