/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/
//"https://www.youtube.com/watch?v=081AqOuasw0"
class Solution {
public:
    int calculate(string s) {
        
        int operand = 0;
        int sign = 1;
        int result = 0;
        int i, size = s.size();
        stack<int>st;
        for( i = 0; i < size; i++ )
        {
            if( isdigit(s[i]) )
            {
                operand = 10*operand + (s[i] - '0');
            }
            else if( s[i] == '+' )
            {
                result += sign*operand;
                sign = 1;
                operand = 0;
            }
            else if( s[i] == '-' )
            {
                result += sign*operand;
                sign = -1;
                operand = 0;
            }
            else if( s[i] == '(' )
            {
                st.push(result);
                st.push(sign);
                sign = 1;
                result = 0;
            }
            else if( s[i] == ')' )
            {
                result += sign*operand;
                sign = st.top();
                st.pop();
                operand = st.top();
                st.pop();
                result = sign*result + operand;
                sign = 1;
                operand = 0;
            }
        }
        return result + sign*operand;
    }
};
