/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5

*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int i, size = s.size();
        if( size == 0 )
            return 0;
        string res = "", res1;
        for( i = 0; i < size; i++ )
        {
            res = "";
            while( s[i] != ' ' && i < size )
            {
                res += s[i];
                i++;
            }
            while( s[i] == ' ' )
                i++;
            i--;
        }
        return res.size();
    }
};
