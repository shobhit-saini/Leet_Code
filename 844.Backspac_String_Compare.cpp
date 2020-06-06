/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        stack<int>s1;
        int size_S = S.size(), size_T = T.size(), i = 0, j = 0;
        string str1 = "", str2 = "";
        
        while( i < size_S )
        {
            if( S[i] == '#' && !s1.empty() )
            {
                s1.pop();
            }
            else if(  S[i] != '#' )
            {
                s1.push(S[i]);
            }
            i++;
        }
        
        while( !s1.empty() )
        {
            str1 += s1.top();
            s1.pop();
        }
        
        while( j < size_T )
        {
            if( T[j] == '#' && !s1.empty() )
            {
                s1.pop();
            }
            else if(  T[j] != '#' )
            {
                s1.push(T[j]);
            }
            j++;
        }
        
        while( !s1.empty() )
        {
            str2 += s1.top();
            s1.pop();
        }
        
        if( str1 == str2 )
            return true;
        return false;
    }
};
