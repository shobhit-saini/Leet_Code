/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/
class Solution {
public:
    string addBinary(string a, string b) {
        
        int size_a = a.size()-1, size_b = b.size()-1, i = size_a, j = size_b, c = 0, val;
        string res = "";
        while( i >= 0 && j >= 0 )
        {
            res = to_string((((a[i]-48) + (b[j]-48) + c) % 2)) + res;
            c = (((a[i]-48) + (b[j]-48) + c) / 2);
            i--;
            j--;
        }
        
        while( i >= 0 )
        {
            res = to_string((((a[i]-48) + c) % 2)) + res;
            c = (((a[i]-48) + c) / 2);
            i--;
        }
        
        while( j >= 0 )
        {
            res = to_string((((b[j]-48) + c) % 2)) + res;
            c = (((b[j]-48) + c) / 2);
            j--;
        }
        if( c == 1 )
        {
            res = '1' + res;
        }
        return res;
    }
};
