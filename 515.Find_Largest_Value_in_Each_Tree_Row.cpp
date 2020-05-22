/*
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        
        queue<TreeNode*>q;
        int max = INT_MIN;
        vector<int>res;
        if( root == NULL )
            return res;
        TreeNode* temp;
        TreeNode* dummy = new TreeNode();
        q.push(root);
        q.push(dummy);
        while( q.size() > 1 )
        {
            temp = q.front();
            if( temp == dummy )
            {
                res.push_back(max);
                max = INT_MIN;
                q.pop();
                q.push( dummy );
                continue;
            }
            if( temp -> left != NULL )
            {
                q.push( temp -> left );

            }
            if( temp -> right != NULL )
            {
                q.push( temp -> right );
            }
            if( max < temp -> val )
                max = temp -> val;
            q.pop();
            
        }
        res.push_back( max );
        return res;
    }
};
