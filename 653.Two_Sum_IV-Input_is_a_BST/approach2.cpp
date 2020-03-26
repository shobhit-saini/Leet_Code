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
    void Inorder(TreeNode* root, vector<int>&v, int &a, map<int, int> &mp,int k)
    {
        if(root == NULL)
            return;
            Inorder(root->left, v, a, mp, k);
            if(mp.find(k-root->val) != mp.end())
            {
                a = 1;
            }
            mp[root->val] = 1;
            Inorder(root->right, v, a, mp, k);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        int a = 0;
        map<int, int> mp;
        Inorder(root, v, a, mp, k);
        if(a == 1)
            return true;
        return false;
    }
};
