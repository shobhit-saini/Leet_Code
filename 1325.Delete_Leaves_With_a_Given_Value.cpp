/*
Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if it's parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you can't).

 

Example 1:



Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).
Example 2:



Input: root = [1,3,3,3,2], target = 3
Output: [1,3,null,null,2]
Example 3:



Input: root = [1,2,null,2,null,2], target = 2
Output: [1]
Explanation: Leaf nodes in green with value (target = 2) are removed at each step.
Example 4:

Input: root = [1,1,1], target = 1
Output: []
Example 5:

Input: root = [1,2,3], target = 1
Output: [1,2,3]
 

Constraints:

1 <= target <= 1000
Each tree has at most 3000 nodes.
Each node's value is between [1, 1000].
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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        vector<pair<TreeNode* , TreeNode*>> v ;
        int flag1 = 0 , flag2 = 0 , i ;
        TreeNode* tmp = root ;
        pair<TreeNode* , TreeNode*> p = {root , tmp } ;
        v.push_back(p) ;
        i = 0 ;
        while(1)
        {
            flag1 = 0; flag2 = 0 ;
            if( v[i].first -> left != NULL )
            {
                flag1 = 1 ;
                p = { v[i].first -> left , v[i].first } ;
                v.push_back(p) ;
            }
            if( v[i].first -> right != NULL )
            {
                flag2 = 1 ;
                p = { v[i].first -> right , v[i].first } ;
                v.push_back(p) ;
            }
            if( i == v.size() - 1 && flag1 == 0 && flag2 == 0)
            {
                break ;
            }
            i++ ;
        }
        for( i = v.size() - 1 ; i >= 0 ; i-- )
        {
            if(i == 0 && (v[i].first) -> val == target && (v[i].first) -> left == NULL && (v[i].second) -> right == NULL )
            {
                return NULL ;
            }
            if((v[i].first) -> val == target && (v[i].first) -> left == NULL && (v[i].first) -> right == NULL )
            {
                if((v[i].second) -> left == v[i].first)
                    v[i].second -> left = NULL ;
                else
                    v[i].second -> right = NULL ;
            }
            
        }
        return root ;
    }
};
