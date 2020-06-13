/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        
        int size1 = num1.size(), size2 = num2.size(), i, j, arr[size1+size2], mul, p1, p2, flag = 0, sum;
        string res = ""; 
        for( i = 0; i < (size1+size2); i++ )
        {
            arr[i] = 0;
        }
        for( i = size1-1; i >= 0; i-- )
        {
            for( j = size2-1; j >= 0; j-- )
            {
                mul = (num1[i]-'0')*(num2[j]-'0');
                p1 = i+j;
                p2 = i+j+1;
                sum = mul + arr[p2];
                
                arr[p2] = sum%10;
                arr[p1] += sum/10;
            }
        }
        
        for( i = 0; i < (size1+size2); i++ )
        {
            if( arr[i] == 0 && flag == 0 )
            {
                
            }
            else
            {
                flag = 1;
                res += to_string(arr[i]);
            }
        }
        if( res.size() == 0 )
            return "0";
        return res;
    }
};
