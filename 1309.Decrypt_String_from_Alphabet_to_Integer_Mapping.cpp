/*
Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
Return the string formed after mapping.

It's guaranteed that a unique mapping will always exist.

 

Example 1:

Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
Example 2:

Input: s = "1326#"
Output: "acz"
Example 3:

Input: s = "25#"
Output: "y"
Example 4:

Input: s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
Output: "abcdefghijklmnopqrstuvwxyz"
 

Constraints:

1 <= s.length <= 1000
s[i] only contains digits letters ('0'-'9') and '#' letter.
s will be valid string such that mapping is always possible.

*/
class Solution {
public:
    string freqAlphabets(string s) {
        
        int i = 0, size = s.size();
        string str = "", res = "";
        map<string, string>mp;
        mp["1"] = "a";
        mp["2"] = "b";
        mp["3"] = "c";
        mp["4"] = "d";
        mp["5"] = "e";
        mp["6"] = "f";
        mp["7"] = "g";
        mp["8"] = "h";
        mp["9"] = "i";
        mp["10#"] = "j";
        mp["11#"] = "k";
        mp["12#"] = "l";
        mp["13#"] = "m";
        mp["14#"] = "n";
        mp["15#"] = "o";
        mp["16#"] = "p";
        mp["17#"] = "q";
        mp["18#"] = "r";
        mp["19#"] = "s";
        mp["20#"] = "t";
        mp["21#"] = "u";
        mp["22#"] = "v";
        mp["23#"] = "w";
        mp["24#"] = "x";
        mp["25#"] = "y";
        mp["26#"] = "z";
        while( i < size )
        {
            if( i+2 < size && s[i+2] == '#' )
            {
                str += s[i];
                str += s[i+1];
                str += s[i+2];
                res += mp[str];
                i = i+3;
                str = "";
            }
            else
            {
                str += s[i];
                res += mp[str];
                i++;
                str = "";
            }
        }
        return res;
    }
};
