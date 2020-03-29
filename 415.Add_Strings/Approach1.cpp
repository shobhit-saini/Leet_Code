/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1, j = num2.size()-1, carry = 0, sum; 
        string str = "";
        while(i >= 0 && j >= 0)
        {
            sum = num1[i] - '0' + num2[j] - '0' + carry;
            str = to_string(sum % 10) + str;
            carry = sum/10;
            i--; j--;
        }
        while(i >= 0)
        {
            sum = num1[i] - '0' + carry;
            carry = sum/10;
            str = to_string(sum % 10) + str;
            i--;
        }
        while(j >= 0)
        {
            sum = num2[j] - '0' + carry;
            carry = sum/10;
            str = to_string(sum % 10) + str;
            j--;
        }
        if(carry == 1)
            str = to_string(carry) + str;
        return str;
    }
};
