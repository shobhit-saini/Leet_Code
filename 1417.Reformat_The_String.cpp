/*
Given alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

Return the reformatted string or return an empty string if it is impossible to reformat the string.

 

Example 1:

Input: s = "a0b1c2"
Output: "0a1b2c"
Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
Example 2:

Input: s = "leetcode"
Output: ""
Explanation: "leetcode" has only characters so we cannot separate them by digits.
Example 3:

Input: s = "1229857369"
Output: ""
Explanation: "1229857369" has only digits so we cannot separate them by characters.
Example 4:

Input: s = "covid2019"
Output: "c2o0v1i9d"
Example 5:

Input: s = "ab123"
Output: "1a2b3"
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters and/or digits.
*/
class Solution {
public:
    string reformat(string s) {
        
        vector<char>alpha, nums, temp1, temp2;
        int size = s.size(), i, j;
        string res = "";
        for( i = 0; i < size; i++ )
        {
            if( isalpha(s[i]) )
                alpha.push_back(s[i]);
            if( isdigit(s[i]) )
                nums.push_back(s[i]);
        }
        if( (abs((int)alpha.size() - (int)nums.size())) > 1 )
            return res;
        if( alpha.size() < nums.size() )
        {
            temp1 = nums;
            temp2 = alpha;
        }
        else
        {
            temp1 = alpha;
            temp2 = nums;
        }
        i = temp1.size()-1, j = temp2.size()-1;
        int flag = 0;
        while( i >= 0 && j >= 0 )
        {
            if( flag == 0 )
            {
                res += temp1[i];
                i--;
                flag = 1;
            }
            else
            {
                res += temp2[j];
                j--;
                flag = 0;
            }
        }
        while(i >= 0)
        {
            res += temp1[i];
            i--;
        }
        while(j >= 0)
        {
            res += temp2[j];
            j--;
        }
        return res;
    }
};
