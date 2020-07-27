/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/
class Solution {
public:
    string reverseWords(string s) {
        
        int size = s.size(), i;
        vector<string>v;
        string str = "", res = "";
        for( i = 0; i < size; i++ )
        {
            if( s[i] == ' ' )
            {
                v.push_back(str);
                str = "";
            }
            else
                str += s[i];
            if( i == size-1 )
                v.push_back(str);
        }
        
        size = v.size();
        for( i = 0; i < size; i++ )
        {
            reverse(v[i].begin(), v[i].end());
            res += v[i];
            if( i != size-1 )
                res += " ";
        }
        return res;
    }
};
