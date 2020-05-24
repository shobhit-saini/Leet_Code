/*
Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

 

Example 1:



Input: root = [2,3,1,3,1,null,1]
Output: 2 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
Example 2:



Input: root = [2,1,1,1,3,null,null,null,null,null,1]
Output: 1 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
Example 3:

Input: root = [9]
Output: 1
 

Constraints:

The given binary tree will have between 1 and 10^5 nodes.
Node values are digits from 1 to 9.
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
    void path_finder( TreeNode* root, vector<vector<int>>&path, vector<int>&v )
    {
        if( root == NULL )
            return;
        v.push_back(root->val);
        if( root -> left == NULL && root -> right == NULL )
        {
            path.push_back(v);
            
            v.pop_back();
            return;
        }
        path_finder(root->left, path, v);
        path_finder(root->right, path, v);
        v.pop_back();
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        
        if( root == NULL )
            return 0;
        vector<vector<int>>path;
        vector<int>v;
        map<int, int>mp;
        int j, size, even = 0, odd = 0, count = 0;
        path_finder(root, path, v);
        map<int, int>:: iterator itr;
        for(int i = 0; i < path.size(); i++)
        {
            size = path[i].size();
            for( j = 0; j < size; j++ )
            {
                mp[path[i][j]]++;
            }
            for( itr = mp.begin(); itr != mp.end(); itr++ )
            {
                if( itr -> second % 2 == 0 )
                    even++;
                else
                    odd++;
            }
            if( size % 2 == 0 )
            {
                if( odd == 0 )
                {
                    count++;
                }
            }
            else
            {
                if( odd == 1 )
                    count++;
            }
            even = 0;
            odd = 0;
            mp.clear();
        }
        return count;
    }
};
