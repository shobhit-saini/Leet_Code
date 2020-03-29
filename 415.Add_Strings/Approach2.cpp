class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1, j = num2.size()-1, carry = 0, sum; 
        string str = "";
        while(i >= 0 || j >= 0)
        {
            sum = 0;
            if(i >= 0) 
                sum += num1[i--] - '0';
            if(j >= 0)
                sum += num2[j--] - '0';
            sum += carry;
            str = to_string(sum % 10) + str;
            carry = sum / 10;
        }
        if(carry == 1)
            str = to_string(carry) + str;
        return str;
    }
};
