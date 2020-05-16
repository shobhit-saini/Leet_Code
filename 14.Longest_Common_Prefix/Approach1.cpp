/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.

*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() == 0)
            return "";
        int i, size = strs[0].size(), j;
        string str = "";
        for(i = 0; i < size; i++)
        {
            for(j = 1; j < strs.size(); j++)
            {
                if(strs[j-1][i] != strs[j][i])
                    return str;
            }
            str += strs[0][i];
        }
        return str;
    }
};
