/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {
        
        queue<TreeNode*>q ;
        vector<double> v1 ;
        double sum , count ;
        if( root == NULL )
            return v1 ;
        TreeNode* tmp ;
        q.push( root ) ;
        q.push( tmp ) ;
        while( q.front() != tmp )
        {
            count = 0 ;
            sum = 0 ;
            while( q.front() != tmp )
            {
                sum += q.front() -> val  ;
                count++ ;
                if( q.front() -> left != NULL )
                    q.push( q.front() -> left ) ;
                
                if( q.front() -> right != NULL )
                    q.push( q.front() -> right ) ;
                
                q.pop() ;
            }
            q.pop() ;
            v1.push_back(sum / count) ;
            q.push(tmp) ;
        }
        return v1 ;
    }
};
