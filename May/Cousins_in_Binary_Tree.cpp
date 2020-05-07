/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
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
    bool isCousins(TreeNode* root, int x, int y) {
        
        int flag1 = 0, flag2 = 0, j = 0, i, k;
        vector<pair<TreeNode*, TreeNode*>>v;
        TreeNode* tmp = new TreeNode();
        pair<TreeNode*, TreeNode*>pr;
        pr = {root, NULL};
        v.push_back(pr);
        pr = {tmp, NULL};
        v.push_back(pr);
        for( i = 0; i < v.size()-1; i++ )
        {
            if( v[i].first == tmp )
            {

                pr = { tmp, NULL };
                v.push_back(pr);
                continue;
            }
            if( v[i].first -> left != NULL )
            {
                pr = {v[i].first->left,v[i].first};
                v.push_back(pr);
            }
            if( v[i].first -> right != NULL )
            {
                pr = {v[i].first->right,v[i].first};
                v.push_back(pr);
            }
        }
        pr = { tmp, NULL };
        v.push_back(pr);
        for( i = 0; i < v.size()-1; i++ )
        {
            if( v[i].first == tmp )
            {
                continue;
            }
            if( v[i].first-> val == x || v[i].first-> val == y )
            {
                k = i;
                for( j = i+1; v[j].first != tmp; j++ )
                {
                    if( (v[j].first-> val == x || v[j].first-> val == y) && v[k].second != v[j].second )
                    {
                        return true;
                    }
                    i++;
                }
            }
        }
        return false;
    }
};
