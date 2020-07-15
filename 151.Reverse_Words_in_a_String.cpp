/*
Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.
*/
class Solution {
public:
    string reverseWords(string s) {
        
        vector<string>words;
        int i, s_size = s.size();
        string str = "";
        for( i = 0; i < s_size; i++ )
        {
            if( s[i] == ' ' )
            {
                if( str != "" )
                    words.push_back(str);
                str = "";
            }
            else
                str += s[i];
        }
        if( str != "" )
            words.push_back(str);
        str = "";
        for( i = words.size()-1; i >= 0; i-- )
        {
            if( i == words.size()-1 )
                str += words[i];
            else
            {
                str += " ";
                str += words[i];
            }
        }
        return str;
    }
};
