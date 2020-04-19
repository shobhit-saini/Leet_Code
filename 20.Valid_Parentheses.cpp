/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/
class Solution {
public:
    bool isValid(string s) {
        
        stack<int> st ;
        int i = 0 , size = s.size() ; 
        if( size == 0 )
            return true ;
        for( i = 0 ; i < size ; )
        {
            if( s[i] == ')' || s[i] == ']' || s[i] == '}' )
                return false ;
            else
                st.push( s[i] ) ;
            i++ ;
            while( !st.empty() )
            {
                if( s[i] == '(' || s[i] == '[' || s[i] == '{' )
                    st.push( s[i] ) ;
                else if( st.top() == '(' && s[i] == ')' )
                        st.pop() ;
                else if( st.top() == '[' && s[i] == ']' )
                        st.pop() ;
                else if( st.top() == '{' && s[i] == '}' )
                        st.pop() ;
                else 
                    return false ;
                i++ ;
            }
        }
        return true ;
    }
};
