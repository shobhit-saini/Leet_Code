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
        
        queue<TreeNode*> q ; 
        int i = 0 ;
        vector<int> v1 ;
        TreeNode* tmp ;
        TreeNode* tmp1 = new TreeNode ;
        vector<vector<int>> v2 ;
          if( root == NULL )
            return v2;
        q.push(root) ;
        q.push(tmp1) ;
        while( q.size() > 1 )
        {
            v1.clear() ;
            while( q.front() != tmp1 )
            {
                tmp = q.front() ;
                if( i % 2 == 0  )
                    v1.push_back(tmp -> val) ;
                else
                    v1.insert(v1.begin() , tmp -> val) ;
                if( tmp -> left != NULL )
                    q.push(tmp -> left) ;
                if( tmp -> right != NULL )
                    q.push(tmp -> right) ;
                q.pop() ;
            }
            q.pop() ;
            q.push(tmp1) ;
            v2.push_back(v1) ;
            i++ ;
        }
        return v2 ;
    }
};
