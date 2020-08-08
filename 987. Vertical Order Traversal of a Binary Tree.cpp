/*
Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.

 

Example 1:



Input: [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation: 
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).
Example 2:



Input: [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation: 
The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report "[1,5,6]", the node value of 5 comes first since 5 is smaller than 6.
 

Note:

The tree will have between 1 and 1000 nodes.
Each node's value will be between 0 and 1000.
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        queue<pair<TreeNode*, int>>q;
        int col = 0, level = 0;
        pair<TreeNode*, int>p;
        TreeNode* temp;
        map<pair<int, int>, vector<int>>mp;
        int var = -1, max = INT_MIN, min = INT_MAX;
        q.push({root, col});
        q.push({NULL,-1});
        while(q.size() > 1)
        {
            if(q.front().first == NULL)
            {
                level++;
                q.push({NULL, -1});
                q.pop();
                continue;
            }
            col = q.front().second;
            temp = q.front().first;
            if(min > col)
                min = col;
            if(max < col)
                max = col;
            q.pop();
            mp[{col,level}].push_back(temp->val);
            if(temp->left)
                q.push({temp->left, col-1});
            if(temp->right)
            {
                q.push({temp->right, col+1});
            }
            var = col;
        }
        map<pair<int, int>, vector<int>>::iterator itr;
        int j = 0;
        vector<vector<int>>res(max-min+1);
        for(itr = mp.begin(); itr != mp.end(); itr++)
        {
            sort(itr->second.begin(), itr->second.end());
        }
        itr = mp.begin();
        var = itr->first.first;
        int i = 0;
        for(itr = mp.begin(); itr != mp.end(); itr++)
        {
            if(itr->first.first == var)
            {
                res[i].insert(res[i].end(), itr->second.begin(), itr->second.end());
            }
            else
            {
                i++;
                var = itr->first.first;
                res[i].insert(res[i].end(), itr->second.begin(), itr->second.end());
            }
        }
        return res;
    }
};
