/*
You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False
*/
class Solution {
public:
    bool checkRecord(string s) {
        
        int size = s.size(), i;
        string a = "", pre1 = "", pre2 = "";
        for( i = 0; i < size; i++ )
        {
            if( s[i] == 'A' && a != "A" )
            {
                a = "A";
                pre2 = pre1;
                pre1 = "A";
            }
            else if( s[i] == 'A' && a == "A" )
            {
                return false;
            }
            if( s[i] == 'L' && pre1 == "L" && pre2 == "L" )
            {
                return false;
            }
            else if( s[i] == 'L' )
            {
                pre2 = pre1;
                pre1 = s[i];
            }
            else
            {
                pre2 = pre1;
                pre1 = s[i];
            }
        }
        return true;
    }
};
