/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
class Solution {
public:
    void letter( vector<string>&str, string& digits, vector<string>&output, string&res, int j )
    {
        if( j == digits.size() )
        {
            output.push_back(res);
            return;
        }
        for( int i = 0; i < str[(digits[j]-'0')-2].size(); i++ )
        {
            string temp = res;
            res += str[(digits[j]-'0')-2][i];
            letter(str, digits, output, res, j+1);
            res = temp;
        }
    }
    vector<string> letterCombinations(string digits) {
        
        vector<string> str;
        str.push_back("abc");
        str.push_back("def");
        str.push_back("ghi");
        str.push_back("jkl");
        str.push_back("mno");
        str.push_back("pqrs");
        str.push_back("tuv");
        str.push_back("wxyz");
        vector<string>output;
        if( digits.size() == 0 )
            return output;
        string res = "";
        letter( str, digits, output, res, 0 );
        return output;
    }
};
