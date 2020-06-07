/*
You are given a string s that consists of lower case English letters and brackets. 

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

 

Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
Example 4:

Input: s = "a(bcdefghijkl(mno)p)q"
Output: "apmnolkjihgfedcbq"
 

Constraints:

0 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It's guaranteed that all parentheses are balanced.
*/
class Solution {
public:
    void reverse(int i, int j, string& str)
    {
        char c;
        while( i <= j )
        {
            if( str[i] == '(' || str[i] == ')' )
                i++;
            else if( str[j] == '(' || str[j] == ')' )
                j--;
            else
            {
                c = str[i];
                str[i] = str[j];
                str[j] = c;
                i++;j--;
            }
        }
    }
    string reverseParentheses(string s) {
        
        stack<int>s1;
        int size = s.size(), i, j;
        string str = s, res = "";
        for( i = 0; i < size; i++ )
        {
            if( s[i] == '(' )
            {
                s1.push(i);
            }
            else if( s[i] == ')' )
            {
                reverse( s1.top(), i, str );
                s1.pop();
            }
        }
        
        for( i = 0; i < size; i++ )
        {
            if( str[i] != '(' && str[i] != ')' )
                res += str[i];
        }
        return res;
    }
};
