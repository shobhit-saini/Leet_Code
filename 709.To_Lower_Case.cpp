/*
Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

 

Example 1:

Input: "Hello"
Output: "hello"
Example 2:

Input: "here"
Output: "here"
Example 3:

Input: "LOVELY"
Output: "lovely"

*/
class Solution {
public:
    string toLowerCase(string str) {
        
        int i, size = str.size();
        for( i = 0; i < size; i++ )
        {
            if( str[i] >= 65 && str[i] <= 90 )
                str[i] = str[i] + 32;
        }
        return str;
    }
};
